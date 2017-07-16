#include "ControlPanel.hpp"


ControlPanel::ControlPanel(): QDockWidget("Control Panel")
{
	scrollArea = new QScrollArea();
	root = new QWidget;
	layout = new QVBoxLayout;
	root->setLayout(layout);
	setWidget(scrollArea);
	
	//Connection section
	connectionGroupBox = new QGroupBox("Connection"); 
	layout->addWidget(connectionGroupBox);
	connectionLayout = new QVBoxLayout;
	connectionLayout->setAlignment (Qt::AlignTop);
	connectionGroupBox->setLayout(connectionLayout);
	
	connectDisconnectButton = new QPushButton("Connect");
	connectionLayout->addWidget(connectDisconnectButton);
	
	connectionStatusLabel = new QLabel;
	connectionStatusLabel->setText("Not Connected");
	connectionLayout->addWidget(connectionStatusLabel);
	
	//Scope Control section
	scanGroupBox = new QGroupBox("Scan"); 
	layout->addWidget(scanGroupBox);
	scanLayout = new QGridLayout;
	scanLayout->setColumnMinimumWidth(0, 100);
	scanLayout->setColumnMinimumWidth(1, 100);
	scanLayout->setColumnStretch(0, 1);
	scanLayout->setColumnStretch(1, 1);
	scanGroupBox->setLayout(scanLayout);
	
	scanLayout->addWidget(new QLabel("Scan Line Speed (samples per second)"), 0, 0, 1, 2);
	scanlineSpeedSpinner = new QDoubleSpinBox();
	scanlineSpeedSpinner->setDecimals(6);
	scanlineSpeedSpinner->setMaximum(10000);
	scanlineSpeedSpinner->setMinimum(0);
	scanlineSpeedSpinner->setSingleStep(1);
	scanLayout->addWidget(scanlineSpeedSpinner, 1, 0);
	
	scanLayout->addWidget(new QLabel("Step Size"), 2, 0, 1, 2);
	scanStepSpinner = new QSpinBox;
	scanStepSpinner->setRange(0, 1000);
    scanStepSpinner->setSingleStep(1);
	scanLayout->addWidget(scanStepSpinner, 3, 0);
	
	scanLayout->addWidget(new QLabel("Start Position"), 4, 0, 1, 2);
	scanPosXSpinner = new QSpinBox;
	scanPosXSpinner->setRange(0, 65535);
    scanPosXSpinner->setSingleStep(1);
	scanLayout->addWidget(scanPosXSpinner, 5, 0);
	scanPosYSpinner = new QSpinBox;
	scanPosYSpinner->setRange(0, 65535);
    scanPosYSpinner->setSingleStep(1);
	scanLayout->addWidget(scanPosYSpinner, 5, 1);
	
	scanLayout->addWidget(new QLabel("Scan Size"), 6, 0, 1, 2);
	scanSizeXSpinner = new QSpinBox;
	scanSizeXSpinner->setRange(0, 65535);
    scanSizeXSpinner->setSingleStep(1);
	scanLayout->addWidget(scanSizeXSpinner, 7, 0);
	scanSizeYSpinner = new QSpinBox;
	scanSizeYSpinner->setRange(0, 65535);
    scanSizeYSpinner->setSingleStep(1);
	scanLayout->addWidget(scanSizeYSpinner, 7, 1);
	
	startScanButton = new QPushButton("Start Scan");
	scanLayout->addWidget(startScanButton, 8, 0);
	
	cancelScanButton = new QPushButton("Cancel Scan");
	scanLayout->addWidget(cancelScanButton, 8, 1);
	
	//Free move section
	freeMoveGroupBox = new QGroupBox("Free Move"); 
	layout->addWidget(freeMoveGroupBox);
	freeMoveLayout = new QGridLayout;
	freeMoveLayout->setColumnMinimumWidth(0, 100);
	freeMoveLayout->setColumnMinimumWidth(1, 100);
	freeMoveLayout->setColumnStretch(0, 1);
	freeMoveLayout->setColumnStretch(1, 1);
	freeMoveGroupBox->setLayout(freeMoveLayout);
	
	positionLabel = new QLabel("Pos X,Y : 0,0", 0, 0);  
	freeMoveLayout->addWidget(positionLabel);
	
	freeMoveLayout->addWidget(new QLabel("Set Position"), 1, 0);
	freePosXSpinner = new QSpinBox;
	freePosXSpinner->setRange(0, 65535);
    freePosXSpinner->setSingleStep(1);
	freeMoveLayout->addWidget(freePosXSpinner, 2, 0);
	freePosYSpinner = new QSpinBox;
	freePosYSpinner->setRange(0, 65535);
    freePosYSpinner->setSingleStep(1);
	freeMoveLayout->addWidget(freePosYSpinner, 2, 1);
	setPositionButton = new QPushButton("Set Position");
	freeMoveLayout->addWidget(setPositionButton);
	
	//Scope Param section
	scopeParamGroupBox = new QGroupBox("Scope Params");
	layout->addWidget(scopeParamGroupBox);
	scopeParamLayout = new QVBoxLayout;
	scopeParamLayout->setAlignment (Qt::AlignTop);
	scopeParamGroupBox->setLayout(scopeParamLayout);
	
	scopeParamLayout->addWidget(new QLabel("Bias Voltage"));
	biasVoltageSpinner = new QDoubleSpinBox();
	biasVoltageSpinner->setDecimals(6);
	biasVoltageSpinner->setMaximum(1000);
	biasVoltageSpinner->setMinimum(-1000);
	biasVoltageSpinner->setSingleStep(0.001);
	scopeParamLayout->addWidget(biasVoltageSpinner);
	
	constantCurrentLock = new QRadioButton("Constant Current Lock");
	scopeParamLayout->addWidget(constantCurrentLock);
	
	scopeParamLayout->addWidget(new QLabel("Tunneling Current Setpoint"));
	tunnelingSetPointSpinner = new QDoubleSpinBox();
	tunnelingSetPointSpinner->setDecimals(6);
	tunnelingSetPointSpinner->setMaximum(100);
	tunnelingSetPointSpinner->setMinimum(-100);
	tunnelingSetPointSpinner->setSingleStep(0.001);
	scopeParamLayout->addWidget(tunnelingSetPointSpinner);
	
	scrollArea->setWidget(root);
}
