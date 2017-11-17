#include "WalkInPlaceTabController.h"
#include <QQuickWindow>
#include <QApplication>
#include "../overlaycontroller.h"
#include <openvr_math.h>
#include <chrono>

// application namespace
namespace walkinplace {


	WalkInPlaceTabController::~WalkInPlaceTabController() {
		if (identifyThread.joinable()) {
			identifyThread.join();
		}
	}


	void WalkInPlaceTabController::initStage1() {
		reloadWalkInPlaceProfiles();
		reloadWalkInPlaceSettings();
	}


	void WalkInPlaceTabController::initStage2(OverlayController * parent, QQuickWindow * widget) {
		this->parent = parent;
		this->widget = widget;
		try {
			vrwalkinplace.connect();
			for (uint32_t id = 0; id < vr::k_unMaxTrackedDeviceCount; ++id) {
				auto deviceClass = vr::VRSystem()->GetTrackedDeviceClass(id);
				if (deviceClass != vr::TrackedDeviceClass_Invalid) {
					if (deviceClass == vr::TrackedDeviceClass_Controller || deviceClass == vr::TrackedDeviceClass_GenericTracker) {
						auto info = std::make_shared<DeviceInfo>();
						info->openvrId = id;
						info->deviceClass = deviceClass;
						char buffer[vr::k_unMaxPropertyStringSize];
						vr::ETrackedPropertyError pError = vr::TrackedProp_Success;
						vr::VRSystem()->GetStringTrackedDeviceProperty(id, vr::Prop_SerialNumber_String, buffer, vr::k_unMaxPropertyStringSize, &pError);
						if (pError == vr::TrackedProp_Success) {
							info->serial = std::string(buffer);
						}
						else {
							info->serial = std::string("<unknown serial>");
							LOG(ERROR) << "Could not get serial of device " << id;
						}
						info->deviceMode = 0;
						deviceInfos.push_back(info);
						LOG(INFO) << "Found device: id " << info->openvrId << ", class " << info->deviceClass << ", serial " << info->serial;
					}
					maxValidDeviceId = id;
				}
			}
			emit deviceCountChanged((unsigned)deviceInfos.size());
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Could not connect to driver component: " << e.what();
		}
	}


	void WalkInPlaceTabController::eventLoopTick(vr::TrackedDevicePose_t* devicePoses) {
		if (settingsUpdateCounter >= 50) {
			settingsUpdateCounter = 0;
			if (parent->isDashboardVisible() || parent->isDesktopMode()) {
				bool newDeviceAdded = false;
				for (uint32_t id = maxValidDeviceId + 1; id < vr::k_unMaxTrackedDeviceCount; ++id) {
					auto deviceClass = vr::VRSystem()->GetTrackedDeviceClass(id);
					if (deviceClass != vr::TrackedDeviceClass_Invalid) {
						if (deviceClass == vr::TrackedDeviceClass_Controller || deviceClass == vr::TrackedDeviceClass_GenericTracker) {
							auto info = std::make_shared<DeviceInfo>();
							info->openvrId = id;
							info->deviceClass = deviceClass;
							char buffer[vr::k_unMaxPropertyStringSize];
							vr::ETrackedPropertyError pError = vr::TrackedProp_Success;
							vr::VRSystem()->GetStringTrackedDeviceProperty(id, vr::Prop_SerialNumber_String, buffer, vr::k_unMaxPropertyStringSize, &pError);
							if (pError == vr::TrackedProp_Success) {
								info->serial = std::string(buffer);
							}
							else {
								info->serial = std::string("<unknown serial>");
								LOG(ERROR) << "Could not get serial of device " << id;
							}

							try {
								//vrwalkinplace::DeviceInfo info2;
								//vrwalkinplace.getDeviceInfo(info->openvrId, info2);
								//info->deviceMode = info2.deviceMode;
								info->deviceMode = 0;
							}
							catch (std::exception& e) {
								LOG(ERROR) << "Exception caught while getting device info: " << e.what();
							}

							deviceInfos.push_back(info);
							LOG(INFO) << "Found device: id " << info->openvrId << ", class " << info->deviceClass << ", serial " << info->serial;
							newDeviceAdded = true;
						}
						maxValidDeviceId = id;
					}
				}
				if (newDeviceAdded) {
					emit deviceCountChanged((unsigned)deviceInfos.size());
				}
			}
		}
		else {
			settingsUpdateCounter++;
		}
	}

	void WalkInPlaceTabController::handleEvent(const vr::VREvent_t&) {
		/*switch (vrEvent.eventType) {
		default:
		break;
		}*/
	}

	unsigned  WalkInPlaceTabController::getDeviceCount() {
		return (unsigned)deviceInfos.size();
	}

	QString WalkInPlaceTabController::getDeviceSerial(unsigned index) {
		if (index < deviceInfos.size()) {
			return QString::fromStdString(deviceInfos[index]->serial);
		}
		else {
			return QString("<ERROR>");
		}
	}

	unsigned WalkInPlaceTabController::getDeviceId(unsigned index) {
		if (index < deviceInfos.size()) {
			return (int)deviceInfos[index]->openvrId;
		}
		else {
			return vr::k_unTrackedDeviceIndexInvalid;
		}
	}

	int WalkInPlaceTabController::getDeviceClass(unsigned index) {
		if (index < deviceInfos.size()) {
			return (int)deviceInfos[index]->deviceClass;
		}
		else {
			return -1;
		}
	}

	int WalkInPlaceTabController::getDeviceState(unsigned index) {
		if (index < deviceInfos.size()) {
			return (int)deviceInfos[index]->deviceStatus;
		}
		else {
			return -1;
		}
	}

	int WalkInPlaceTabController::getDeviceMode(unsigned index) {
		if (index < deviceInfos.size()) {
			return (int)deviceInfos[index]->deviceMode;
		}
		else {
			return -1;
		}
	}

	bool WalkInPlaceTabController::isStepDetectionEnabled() {
		for (int index = 0; index < deviceInfos.size(); index++) {
			if (deviceInfos[index]->stepDetectionEnabled) {
				return true;
			}
		}
		return false;
	}

	float WalkInPlaceTabController::getStepIntSec() {
		return stepIntSec;
	}

	int WalkInPlaceTabController::getGameType() {
		return gameType;
	}

	float WalkInPlaceTabController::getHMDXZThreshold() {
		return hmdThreshold.v[0];
	}

	float WalkInPlaceTabController::getHMDYThreshold() {
		return hmdThreshold.v[1];
	}

	float WalkInPlaceTabController::getHandWalkThreshold() {
		return handWalkThreshold;
	}

	float WalkInPlaceTabController::getHandJogThreshold() {
		return handJogThreshold;
	}

	float WalkInPlaceTabController::getHandRunThreshold() {
		return handRunThreshold;
	}

	float WalkInPlaceTabController::getWalkTouch() {
		return walkTouch;
	}

	float WalkInPlaceTabController::getJogTouch() {
		return jogTouch;
	}

	float WalkInPlaceTabController::getRunTouch() {
		return runTouch;
	}


#define WALKINPLACESETTINGS_GETHMDTHRESHOLDS(name) { \
	float y = settings->value(#name ## "_y", 0.13).toFloat(); \
	float xz = settings->value(#name ## "_xz", 0.13).toFloat(); \
	entry.name = { xz, y, xz }; \
}

#define WALKINPLACESETTINGS_GETWALKSWINGVAL(name) { \
	float walk = settings->value(#name ## "_walk", 0.02).toFloat(); \
	entry.name = walk; \
}

#define WALKINPLACESETTINGS_GETJOGSWINGVAL(name) { \
	float jog = settings->value(#name ## "_jog", 0.4).toFloat(); \
	entry.name = jog; \
}

#define WALKINPLACESETTINGS_GETRUNSWINGVAL(name) { \
	float run = settings->value(#name ## "_run", 1.7).toFloat(); \
	entry.name = run; \
}

#define WALKINPLACESETTINGS_GETGAMETYPE(name) { \
	int type = settings->value(#name ## "_gametype", 1).toInt(); \
	entry.name = type; \
}

#define WALKINPLACESETTINGS_GETWALKTOUCH(name) { \
	float type = settings->value(#name ## "_walktouch", 0.6).toFloat(); \
	entry.name = type; \
}

#define WALKINPLACESETTINGS_GETJOGTOUCH(name) { \
	float type = settings->value(#name ## "_jogtouch", 0.9).toFloat(); \
	entry.name = type; \
}

#define WALKINPLACESETTINGS_GETRUNTOUCH(name) { \
	float type = settings->value(#name ## "_runtouch", 1.0).toFloat(); \
	entry.name = type; \
}

	void WalkInPlaceTabController::reloadWalkInPlaceSettings() {
		auto settings = OverlayController::appSettings();
		settings->beginGroup("walkInPlaceSettings");
		settings->endGroup();
	}

	void WalkInPlaceTabController::reloadWalkInPlaceProfiles() {
		walkInPlaceProfiles.clear();
		auto settings = OverlayController::appSettings();
		settings->beginGroup("walkInPlaceSettings");
		auto profileCount = settings->beginReadArray("walkInPlaceProfiles");
		for (int i = 0; i < profileCount; i++) {
			settings->setArrayIndex(i);
			walkInPlaceProfiles.emplace_back();
			auto& entry = walkInPlaceProfiles[i];
			entry.profileName = settings->value("profileName").toString().toStdString();
			entry.stepDetectionEnabled = settings->value("stepDetectionEnabled", false).toBool();
			WALKINPLACESETTINGS_GETHMDTHRESHOLDS(hmdThreshold);
			WALKINPLACESETTINGS_GETWALKSWINGVAL(handWalkThreshold);
			WALKINPLACESETTINGS_GETJOGSWINGVAL(handJogThreshold);
			WALKINPLACESETTINGS_GETRUNSWINGVAL(handRunThreshold);
			WALKINPLACESETTINGS_GETGAMETYPE(gameType);
			WALKINPLACESETTINGS_GETWALKTOUCH(walkTouch);
			WALKINPLACESETTINGS_GETJOGTOUCH(jogTouch);
			WALKINPLACESETTINGS_GETRUNTOUCH(runTouch);
		}
		settings->endArray();
		settings->endGroup();
	}

	void WalkInPlaceTabController::saveWalkInPlaceSettings() {
		auto settings = OverlayController::appSettings();
		settings->beginGroup("walkInPlaceSettings");
		settings->endGroup();
		settings->sync();
	}



#define WALKINPLACESETTINGS_WRITEHMDTHRESHOLDS(name) { \
	auto& vec = p.name; \
	settings->setValue(#name ## "_y", vec.v[1]); \
	settings->setValue(#name ## "_xz", vec.v[0]); \
}

#define WALKINPLACESETTINGS_WRITEWALKSWINGVAL(name) { \
    auto& walk = p.name; \
	settings->setValue(#name ## "_walk", walk); \
}

#define WALKINPLACESETTINGS_WRITEJOGSWINGVAL(name) { \
    auto& jog = p.name; \
	settings->setValue(#name ## "_jog", jog); \
}

#define WALKINPLACESETTINGS_WRITERUNSWINGVAL(name) { \
    auto& run = p.name; \
	settings->setValue(#name ## "_run", run); \
}

#define WALKINPLACESETTINGS_WRITEGAMETYPE(name) { \
    auto& type = p.name; \
	settings->setValue(#name ## "_gametype", type); \
}

#define WALKINPLACESETTINGS_WRITEWALKTOUCH(name) { \
    auto& type = p.name; \
	settings->setValue(#name ## "_walktouch", type); \
}

#define WALKINPLACESETTINGS_WRITEJOGTOUCH(name) { \
    auto& type = p.name; \
	settings->setValue(#name ## "_jogtouch", type); \
}

#define WALKINPLACESETTINGS_WRITERUNTOUCH(name) { \
    auto& type = p.name; \
	settings->setValue(#name ## "_runtouch", type); \
}


	void WalkInPlaceTabController::saveWalkInPlaceProfiles() {
		auto settings = OverlayController::appSettings();
		settings->beginGroup("walkInPlaceSettings");
		settings->beginWriteArray("walkInPlaceProfiles");
		unsigned i = 0;
		for (auto& p : walkInPlaceProfiles) {
			settings->setArrayIndex(i);
			settings->setValue("profileName", QString::fromStdString(p.profileName));
			settings->setValue("stepDetectionEnabled", p.stepDetectionEnabled);
			WALKINPLACESETTINGS_WRITEHMDTHRESHOLDS(hmdThreshold);
			WALKINPLACESETTINGS_WRITEWALKSWINGVAL(handWalkThreshold);
			WALKINPLACESETTINGS_WRITEJOGSWINGVAL(handJogThreshold);
			WALKINPLACESETTINGS_WRITERUNSWINGVAL(handRunThreshold);
			WALKINPLACESETTINGS_WRITEGAMETYPE(gameType);
			WALKINPLACESETTINGS_WRITEWALKTOUCH(walkTouch);
			WALKINPLACESETTINGS_WRITEJOGTOUCH(jogTouch);
			WALKINPLACESETTINGS_WRITERUNTOUCH(runTouch);
			i++;
		}
		settings->endArray();
		settings->endGroup();
		settings->sync();
	}

	unsigned WalkInPlaceTabController::getWalkInPlaceProfileCount() {
		return (unsigned)walkInPlaceProfiles.size();
	}

	QString WalkInPlaceTabController::getWalkInPlaceProfileName(unsigned index) {
		if (index >= walkInPlaceProfiles.size()) {
			return QString();
		}
		else {
			return QString::fromStdString(walkInPlaceProfiles[index].profileName);
		}
	}

	void WalkInPlaceTabController::addWalkInPlaceProfile(QString name) {
		WalkInPlaceProfile* profile = nullptr;
		for (auto& p : walkInPlaceProfiles) {
			if (p.profileName.compare(name.toStdString()) == 0) {
				profile = &p;
				break;
			}
		}
		if (!profile) {
			auto i = walkInPlaceProfiles.size();
			walkInPlaceProfiles.emplace_back();
			profile = &walkInPlaceProfiles[i];
		}
		profile->profileName = name.toStdString();
		profile->stepDetectionEnabled = isStepDetectionEnabled();
		profile->hmdThreshold = hmdThreshold;
		profile->handJogThreshold = handJogThreshold;
		profile->handRunThreshold = handRunThreshold;
		profile->gameType = gameType;
		profile->walkTouch = walkTouch;
		profile->jogTouch = jogTouch;
		profile->runTouch = runTouch;
		saveWalkInPlaceProfiles();
		OverlayController::appSettings()->sync();
		emit walkInPlaceProfilesChanged();
	}

	void WalkInPlaceTabController::applyWalkInPlaceProfile(unsigned index) {
		if (index < walkInPlaceProfiles.size()) {
			auto& profile = walkInPlaceProfiles[index];
			hmdThreshold.v[0] = profile.hmdThreshold.v[0];
			hmdThreshold.v[1] = profile.hmdThreshold.v[1];
			hmdThreshold.v[2] = profile.hmdThreshold.v[2];
			handJogThreshold = profile.handJogThreshold;
			handRunThreshold = profile.handRunThreshold;
			walkTouch = profile.walkTouch;
			jogTouch = profile.jogTouch;
			runTouch = profile.runTouch;
			gameType = profile.gameType;
			enableStepDetection(profile.stepDetectionEnabled);
			setHMDThreshold(profile.hmdThreshold.v[0], profile.hmdThreshold.v[1], profile.hmdThreshold.v[2]);
			setHandJogThreshold(profile.handJogThreshold);
			setHandRunThreshold(profile.handRunThreshold);
			setGameStepType(profile.gameType);
			setWalkTouch(profile.walkTouch);
			setJogTouch(profile.jogTouch);
			setRunTouch(profile.runTouch);
		}
	}

	void WalkInPlaceTabController::deleteWalkInPlaceProfile(unsigned index) {
		if (index < walkInPlaceProfiles.size()) {
			auto pos = walkInPlaceProfiles.begin() + index;
			walkInPlaceProfiles.erase(pos);
			saveWalkInPlaceProfiles();
			OverlayController::appSettings()->sync();
			emit walkInPlaceProfilesChanged();
		}
	}


	void WalkInPlaceTabController::enableStepDetection(bool enable) {
		try {
			vrwalkinplace.enableStepDetection(enable);
			for (int index = 0; index < deviceInfos.size(); index++) {
				deviceInfos[index]->stepDetectionEnabled = enable;
			}
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting step detection: " << e.what();
		}
	}

	void WalkInPlaceTabController::setStepIntSec(float value) {
		try {
			vrwalkinplace.setStepIntSec(value);
			stepIntSec = value;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting step integration second: " << e.what();
		}
	}

	void WalkInPlaceTabController::setWalkTouch(float value) {
		try {
			vrwalkinplace.setWalkTouch(value);
			walkTouch = value;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting walk touch: " << e.what();
		}
	}

	void WalkInPlaceTabController::setJogTouch(float value) {
		try {
			vrwalkinplace.setJogTouch(value);
			jogTouch = value;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting jog touch: " << e.what();
		}
	}

	void WalkInPlaceTabController::setRunTouch(float value) {
		try {
			vrwalkinplace.setRunTouch(value);
			runTouch = value;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting run touch: " << e.what();
		}
	}

	void WalkInPlaceTabController::setHMDThreshold(float x, float y, float z) {
		try {
			vr::HmdVector3d_t value = { x, y, z };
			vrwalkinplace.setHMDThreshold(value);
			hmdThreshold.v[0] = x;
			hmdThreshold.v[1] = y;
			hmdThreshold.v[2] = z;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting hmd threshold: " << e.what();
		}
	}

	void WalkInPlaceTabController::setHandWalkThreshold(float walkThreshold) {
		try {
			handWalkThreshold = walkThreshold;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting hand threshold: " << e.what();
		}
	}

	void WalkInPlaceTabController::setHandJogThreshold(float jogThreshold) {
		try {
			vrwalkinplace.setHandJogThreshold(jogThreshold);
			handJogThreshold = jogThreshold;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting hand threshold: " << e.what();
		}
	}

	void WalkInPlaceTabController::setHandRunThreshold(float runThreshold) {
		try {
			vrwalkinplace.setHandRunThreshold(runThreshold);
			handRunThreshold = runThreshold;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting hand threshold: " << e.what();
		}
	}

	void WalkInPlaceTabController::setGameStepType(int type) {
		try {
			vrwalkinplace.setGameStepType(type);
			gameType = type;
		}
		catch (const std::exception& e) {
			LOG(ERROR) << "Exception caught while setting hand threshold: " << e.what();
		}
	}

} // namespace walkinplace