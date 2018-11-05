import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import pottedmeat7.walkinplace 1.0

MyMainViewPage {
    id: stepDetectionPage
    name: "stepDetectionPage"
    property var initialLoaded: false

    function updateInfo() {  
        stepThresholdBox.setHMDY(WalkInPlaceTabController.getHMDYThreshold())
        stepThresholdBox.setHMDXZ(WalkInPlaceTabController.getHMDXZThreshold())
        stepThresholdBox.setHandJog(WalkInPlaceTabController.getHandJogThreshold())
        stepThresholdBox.setHandRun(WalkInPlaceTabController.getHandRunThreshold())
        stepThresholdBox.setUseTrackers(WalkInPlaceTabController.getUseTrackers())
        stepThresholdBox.setDisableHMD(WalkInPlaceTabController.getDisableHMD())
        stepThresholdBox.setTrackerY(WalkInPlaceTabController.getTrackerYThreshold())
        stepThresholdBox.setTrackerXZ(WalkInPlaceTabController.getTrackerXZThreshold())
        stepThresholdBox.setStepTime(WalkInPlaceTabController.getStepTime())
        stepControlBox.setWalkTouch(WalkInPlaceTabController.getWalkTouch())
        stepControlBox.setJogTouch(WalkInPlaceTabController.getJogTouch())
        stepControlBox.setRunTouch(WalkInPlaceTabController.getRunTouch())
        stepControlBox.setUseContDirForStraf(WalkInPlaceTabController.getUseContDirForStraf())
        stepControlBox.setUseContDirForRev(WalkInPlaceTabController.getUseContDirForRev())
        stepControlBox.updateGUI()
        stepThresholdBox.updateGUI()    
        stepDetectionEnableToggle.checked = WalkInPlaceTabController.isStepDetectionEnabled()
        gameTypeDialog.currentIndex = WalkInPlaceTabController.getGameType()
        hmdTypeDialog.currentIndex = WalkInPlaceTabController.getHMDType()
        controlSelect.currentIndex = WalkInPlaceTabController.getControlSelect() == 0 ? 1 : 0
        buttonMode.currentIndex = WalkInPlaceTabController.getAccuracyButtonFlip() ? 0 : 1
        accuracyButtonDialog.currentIndex = WalkInPlaceTabController.getAccuracyButton()
        buttonControlSelect.currentIndex = WalkInPlaceTabController.getAccuracyButtonControlSelect()
    }

    function setAutoConfHMDY(v) {
        stepThresholdBox.setHMDY(v)
    }

    function setAutoConfHMDXZ(v) {
        stepThresholdBox.setHMDXZ(v)
    }

    function setAutoConfUseTrackers(v) {
        stepThresholdBox.setUseTrackers(v)
    }

    function setAutoConfDisableHMD(v) {
        stepThresholdBox.setDisableHMD(v)
    }

    function setAutoConfTRKY(v) {
        stepThresholdBox.setTrackerY(v)
    }

    function setAutoConfTRKXZ(v) {
        stepThresholdBox.setTrackerXZ(v)
    }

    function setAutoConfContMin(v) {
    }

    function setAutoConfContMid(v) {
        stepThresholdBox.setHandJog(v)
    }

    function setAutoConfContMax(v) {
        stepThresholdBox.setHandRun(v)
    }

    content: ColumnLayout {
        anchors.top: parent.top
        spacing: 20

        GroupBox {
            Layout.fillWidth: true
            
            background: Rectangle {
                color: "#c0c0c0" // "#277650"
                border.color: "#dddddd"
                radius: 1
            }

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter

                RowLayout {
                    MyText {
                        color: "#000000"
                        id: headerTitle
                        text: "OpenVR-WalkInPlace"
                        font.pointSize: 22
                    }
                }
            }
        }

        GroupBox {

            Layout.fillWidth: true
            
            background: Rectangle {
                color: "#c0c0c0" // "#277650"
                border.color: "#000000"
                radius: 1
            }

            ColumnLayout {
                anchors.fill: parent
                Layout.alignment: Qt.AlignHCenter

                GridLayout {
                    columns: 6

                    MyToggleButton {
                        id: stepDetectionEnableToggle
                        text: "Enable WIP"
                        Layout.maximumWidth: 200
                        Layout.minimumWidth: 200
                        Layout.preferredWidth: 200
                        Layout.fillWidth: true
                        onCheckedChanged: {
                            WalkInPlaceTabController.enableStepDetection(checked)
                        }
                    }


                    MyComboBox {
                        id: hmdTypeDialog 
                        currentIndex: 0
                        Layout.maximumWidth: 100
                        Layout.minimumWidth: 100
                        Layout.preferredWidth: 100
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["Vive", "WMR", "Rift"]
                        onCurrentIndexChanged: {
                            if (currentIndex >= 0) { 
                                WalkInPlaceTabController.setHMDType(currentIndex)                            
                            } 
                        }
                    }

                    MyComboBox {
                        id: gameTypeDialog 
                        currentIndex: 0
                        Layout.maximumWidth: 400
                        Layout.minimumWidth: 400
                        Layout.preferredWidth: 400
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["touchpad (click sprint)", "touchpad", "touchpad (pressed)", "thumbsticks (click sprint)", "thumbsticks", "thumbsticks (pressed)","hold grip", "Keyboard (WASD)", "Keyboard (Arrows)"]
                        onCurrentIndexChanged: {
                            if (currentIndex >= 0) { 
                                WalkInPlaceTabController.setGameStepType(currentIndex)                            
                            } 
                        }
                    }
  

                    MyText {
                        text: " "
                        Layout.preferredWidth: 10
                    }  

                    MyText {
                        text: "on"
                        Layout.preferredWidth: 50
                    }

                    MyComboBox {
                        id: controlSelect 
                        currentIndex: 0
                        Layout.maximumWidth: 250
                        Layout.minimumWidth: 250
                        Layout.preferredWidth: 250
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["Left Controller", "Right Controller"]
                        onCurrentIndexChanged: {
                            if (currentIndex == 0) { 
                                WalkInPlaceTabController.setControlSelect(1)   
                            } 
                            if (currentIndex == 1) { 
                                WalkInPlaceTabController.setControlSelect(0)   
                            } 
                            //switchVirtualHandInput.openPopup()
                        }
                    }

                }

                GridLayout {
                    columns: 5
                    
                    MyComboBox {
                        id: buttonMode 
                        currentIndex: 0
                        Layout.maximumWidth: 305
                        Layout.minimumWidth: 305
                        Layout.preferredWidth: 305
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["Disable WIP", "Enable WIP"]
                        onCurrentIndexChanged: {
                            if (currentIndex == 0) { 
                                WalkInPlaceTabController.disableByButton(true)
                            }
                            else if (currentIndex == 1) { 
                                WalkInPlaceTabController.disableByButton(false)
                            } 
                        }
                    }

                    MyComboBox {
                        id: accuracyButtonDialog 
                        currentIndex: 0
                        Layout.maximumWidth: 401
                        Layout.minimumWidth: 401
                        Layout.preferredWidth: 401
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["by holding grip", "by holding trigger", "only with thresholds"]
                        onCurrentIndexChanged: {
                            if (currentIndex >= 0) { 
                                WalkInPlaceTabController.setAccuracyButton(currentIndex) 
                            } 
                        }
                    }     

                    MyText {
                        text: " "
                        Layout.preferredWidth: 10
                    }  

                    MyText {
                        text: "on"
                        Layout.preferredWidth: 50
                    }

                    MyComboBox {
                        id: buttonControlSelect 
                        currentIndex: 0
                        Layout.maximumWidth: 250
                        Layout.minimumWidth: 250
                        Layout.preferredWidth: 250
                        Layout.fillWidth: true
                        displayText: currentText
                        model: ["1st Controller", "2nd Controller"]
                        onCurrentIndexChanged: {
                            if (currentIndex >= 0) { 
                               WalkInPlaceTabController.setAccuracyButtonControlSelect(currentIndex)                        
                            } 
                        }
                    }
                }
            }
        }

        StepDetectConfBox2 {
            id: stepThresholdBox
            keyboardUIDBase: 100
            setHMDXZ: function(xz) {
                WalkInPlaceTabController.setHMDThreshold(xz,hmdY,xz)
                hmdXZ = xz
                updateGUI()    
            }
            setHMDY: function(y) {
                WalkInPlaceTabController.setHMDThreshold(hmdXZ,y,hmdXZ)
                hmdY = y
                updateGUI()    
            }
            setUseTrackers: function(val) {
                WalkInPlaceTabController.setUseTrackers(val)
                useTrackers = val
                updateGUI()    
            }
            setDisableHMD: function(val) {
                WalkInPlaceTabController.setDisableHMD(val)
                disableHMD = val
                setUseTrackers(useTrackers || val)
            }
            setTrackerXZ: function(xz) {
                trackerXZ = xz
                WalkInPlaceTabController.setTrackerThreshold(xz,trackerY,xz)
                updateGUI()    
            }
            setTrackerY: function(y) {
                trackerY = y
                WalkInPlaceTabController.setTrackerThreshold(trackerXZ,y,trackerXZ)
                updateGUI()    
            }
            setHandJog: function(jog) {
                WalkInPlaceTabController.setHandJogThreshold(jog)
                handJog = jog
                updateGUI()    
            }
            setHandRun: function(run) {
                WalkInPlaceTabController.setHandRunThreshold(run)
                handRun = run
                updateGUI()    
            }
            setStepTime: function(t) {
                WalkInPlaceTabController.setStepTime(t)
                stepTime = t
                updateGUI()                 
            }
            updateValues: function() {
                updateGUI()
            }
        }

        StepDetectConfBox4 {
            boxTitle: "Virtual Input"
            id: stepControlBox
            keyboardUIDBase: 119
            setWalkTouch: function(val) {
                WalkInPlaceTabController.setWalkTouch(val)
                walkTouch = val
                updateGUI()
            }
            setJogTouch: function(val) {
                WalkInPlaceTabController.setJogTouch(val)
                jogTouch = val
                updateGUI()
            }
            setRunTouch: function(val) {
                WalkInPlaceTabController.setRunTouch(val)
                runTouch = val
                updateGUI()
            }
            setScaleTouch: function(val) {
                WalkInPlaceTabController.setScaleTouchWithSwing(val)
                scaleTouch = val
                updateGUI()
            }
            setUseContDirForStraf: function(val) {
                WalkInPlaceTabController.setUseContDirForStraf(val)
                useContDirForStraf = val
                updateGUI()
            }
            setUseContDirForRev: function(val) {
                WalkInPlaceTabController.setUseContDirForRev(val)
                useContDirForRev = val
                updateGUI()
            }
        }


        ColumnLayout {
            spacing: 18
            Layout.alignment: Qt.AlignHCenter

            GroupBox {

                height: 200
                Layout.fillWidth: true
                
                background: Rectangle {
                    color: "#c0c0c0" // "#277650"
                    border.color: "#000000"
                    radius: 1
                }

                ColumnLayout {
                    anchors.fill: parent

                    RowLayout {
                        spacing: 18

                        Button {
                            id: walkInPlaceLoadProfiles
                            Layout.preferredWidth: 200
                            text: "Load Profiles"
                            onClicked: {
                                reloadWalkInPlaceProfiles()
                            }
                        }

                        MyComboBox {
                            id: walkInPlaceProfileComboBox
                            Layout.maximumWidth: 310
                            Layout.minimumWidth: 310
                            Layout.preferredWidth: 310
                            Layout.fillWidth: true
                            model: [""]
                            onCurrentIndexChanged: {
                                if (currentIndex > 0) {
                                    walkInPlaceApplyProfileButton.enabled = true
                                    walkInPlaceDeleteProfileButton.enabled = true
                                } else {
                                    walkInPlaceApplyProfileButton.enabled = false
                                    walkInPlaceDeleteProfileButton.enabled = false
                                }
                            }
                        }

                        MyPushButton {
                            id: walkInPlaceApplyProfileButton
                            enabled: false
                            Layout.preferredWidth: 150
                            text: "Apply"
                            onClicked: {
                                if (walkInPlaceProfileComboBox.currentIndex > 0) {
                                    WalkInPlaceTabController.applyWalkInPlaceProfile(walkInPlaceProfileComboBox.currentIndex - 1);
                                    updateInfo()
                                }
                            }
                        }

                        MyPushButton {
                            id: walkInPlaceNewProfileButton
                            Layout.preferredWidth: 150
                            text: "New Profile"
                            onClicked: {
                                walkInPlaceNewProfileDialog.openPopup()
                            }
                        }

                        MyPushButton {
                            id: walkInPlaceDeleteProfileButton
                            enabled: false
                            Layout.preferredWidth: 180
                            text: "Delete Profile"
                            onClicked: {
                                if (walkInPlaceProfileComboBox.currentIndex > 0) {
                                    walkInPlaceDeleteProfileDialog.profileIndex = walkInPlaceProfileComboBox.currentIndex - 1
                                    walkInPlaceDeleteProfileDialog.open()
                                }
                            }
                        }
                    }

                    RowLayout {
                        spacing: 18

                        MyPushButton {
                            Layout.preferredWidth: 100
                            text: "Reset"
                            onClicked: { 
                                stepThresholdBox.setHMDY(0.12)
                                stepThresholdBox.setHMDXZ(0.2)
                                stepThresholdBox.setHandJog(1.2)
                                stepThresholdBox.setHandRun(2.1)
                                stepThresholdBox.setUseTrackers(false)
                                stepThresholdBox.setDisableHMD(false)
                                stepThresholdBox.setTrackerY(0.12)
                                stepThresholdBox.setTrackerXZ(0.2)
                                stepThresholdBox.setStepTime(0.4)
                                stepControlBox.setWalkTouch(0.4)
                                stepControlBox.setJogTouch(1)
                                stepControlBox.setRunTouch(1)
                                stepControlBox.setUseContDirForStraf(false)
                                stepControlBox.setUseContDirForRev(false)
                                stepControlBox.updateGUI()
                                stepThresholdBox.updateGUI()
                                stepDetectionEnableToggle.checked = false
                                gameTypeDialog.currentIndex = 0
                                hmdTypeDialog.currentIndex = 0
                                controlSelect.currentIndex = 0
                                buttonMode.currentIndex = 0
                                accuracyButtonDialog.currentIndex = 0
                                buttonControlSelect.currentIndex = 0
                            }
                        }

                        MyPushButton {
                            text: "Auto Configuration & Velocity Graph"
                            onClicked: {
                                WalkInPlaceTabController.setupStepGraph()
                                var res = mainView.push(stepDetectGraphPage)
                                mainView.startTimer()
                            }
                        }
                    }
                }
            }
        }

        Component.onCompleted: {   
            if ( !initialLoaded ) { 
                updateInfo()
            }
            initialLoaded = true
            //reloadWalkInPlaceProfiles()            
        }

        Connections {
            target: WalkInPlaceTabController
            onWalkInPlaceProfilesChanged: {
                reloadWalkInPlaceProfiles()
                updateInfo()
            }
        }

    }

    MyDialogOkCancelPopup {
        id: walkInPlaceDeleteProfileDialog
        property int profileIndex: -1
        dialogTitle: "Delete Profile"
        dialogText: "Do you really want to delete this profile?"
        onClosed: {
            if (okClicked) {
                WalkInPlaceTabController.deleteWalkInPlaceProfile(profileIndex)
            }
        }
    }

    MyDialogOkCancelPopup {
        id: walkInPlaceNewProfileDialog
        dialogTitle: "Create New Profile"
        dialogWidth: 600
        dialogHeight: 400
        dialogContentItem: ColumnLayout {
            RowLayout {
                Layout.topMargin: 16
                Layout.leftMargin: 16
                Layout.rightMargin: 16
                MyText {
                    text: "Name: "
                }
                MyTextField {
                    id: walkInPlaceNewProfileName
                    color: "#000000"
                    text: ""
                    Layout.fillWidth: true
                    font.pointSize: 20
                    function onInputEvent(input) {
                        text = input
                    }
                }
            }
        }
        onClosed: {
            if (okClicked) {
                if (walkInPlaceNewProfileName.text == "") {
                    walkInPlaceMessageDialog.showMessage("Create New Profile", "ERROR: Empty profile name.")
                } else {
                    WalkInPlaceTabController.addWalkInPlaceProfile(walkInPlaceNewProfileName.text)
                }
            }
        }
        function openPopup() {
            walkInPlaceNewProfileName.text = ""
            open()
        }
    }

    MyDialogOkCancelPopup {
        id: switchVirtualHandInput
        dialogTitle: "Reinit Virtual Controller Hand Role?"
        dialogWidth: 800
        dialogHeight: 600
        dialogContentItem: ColumnLayout {
            RowLayout {
                MyText {
                    text: "This will power off the current"
                } 
            }
            RowLayout {
                MyText {
                    text: "left/right virtual controller and"
                } 
            }
            RowLayout {
                MyText {
                    text: "set it to the selected option."
                } 
            }
            RowLayout {
                MyText {
                    text: "After the new virtual controller is added,"
                } 
            }
            RowLayout {
                MyText {
                    text: "its best if you power off and on the"
                } 
            }
            RowLayout {
                MyText {
                    text: "physical left/right controller."
                }
            }
        }
        onClosed: {
            if (okClicked) {
                WalkInPlaceTabController.reinitVirContToCurHand()
            }
        }
        function openPopup() {
            open()
        }
    }

    function reloadWalkInPlaceProfiles() {
        var profiles = [""]
        var profileCount = WalkInPlaceTabController.getWalkInPlaceProfileCount()
        var defaultFound = -1
        for (var i = 0; i < profileCount; i++) {
            var p_name = WalkInPlaceTabController.getWalkInPlaceProfileName(i)
            if ( p_name == "default" ) {
                defaultFound = i
            }
            profiles.push(p_name)
        }
        walkInPlaceProfileComboBox.model = profiles
        walkInPlaceProfileComboBox.currentIndex = 0
        if ( defaultFound >= 0 ) {
            WalkInPlaceTabController.applyWalkInPlaceProfile(defaultFound);
            walkInPlaceProfileComboBox.currentIndex = defaultFound+1
            updateInfo()
        }
    }

}
