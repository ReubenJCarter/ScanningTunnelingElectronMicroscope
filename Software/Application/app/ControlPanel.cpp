#include "ControlPanel.hpp"


ControlPanel::ControlPanel(): QDockWidget("Control Panel")
{
	root = new QWidget;
	layout = new QVBoxLayout;
	root->setLayout(layout);
	setWidget(root);
	
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
	scanLayout = new QVBoxLayout;
	scanLayout->setAlignment (Qt::AlignTop);
	scanGroupBox->setLayout(scanLayout);
	
	scanLayout->addWidget(new QLabel("Scan Line Speed (samples per second)"));
	scanlineSpeedSpinner = new QDoubleSpinBox();
	scanlineSpeedSpinner->setDecimals(6);
	scanlineSpeedSpinner->setMaximum(10000);
	scanlineSpeedSpinner->setMinimum(0);
	scanlineSpeedSpinner->setSingleStep(1);
	scanLayout->addWidget(scanlineSpeedSpinner);
	
	scanLayout->addWidget(new QLabel("Step Size"));
	scanStepSpinner = new QSpinBox;
	scanStepSpinner->setRange(0, 1000);
    scanStepSpinner->setSingleStep(1);
	scanLayout->addWidget(scanStepSpinner);
	
	scanLayout->addWidget(new QLabel("Start Position"));
	scanPosXSpinner = new QSpinBox;
	scanPosXSpinner->setRange(0, 65535);
    scanPosXSpinner->setSingleStep(1);
	scanLayout->addWidget(scanPosXSpinner);
	scanPosYSpinner = new QSpinBox;
	scanPosYSpinner->setRange(0, 65535);
    scanPosYSpinner->setSingleStep(1);
	scanLayout->addWidget(scanPosYSpinner);
	
	scanLayout->addWidget(new QLabel("Scan Size"));
	scanSizeXSpinner = new QSpinBox;
	scanSizeXSpinner->setRange(0, 65535);
    scanSizeXSpinner->setSingleStep(1);
	scanLayout->addWidget(scanSizeXSpinner);
	scanSizeYSpinner = new QSpinBox;
	scanSizeYSpinner->setRange(0, 65535);
    scanSizeYSpinner->setSingleStep(1);
	scanLayout->addWidget(scanSizeYSpinner);
	
	startScanButton = new QPushButton("Start Scan");
	scanLayout->addWidget(startScanButton);
	
	cancelScanButton = new QPushButton("Cancel Scan");
	scanLayout->addWidget(cancelScanButton);
	
	//Free move section
	freeMoveGroupBox = new QGroupBox("Free Move"); 
	layout->addWidget(freeMoveGroupBox);
	freeMoveLayout = new QVBoxLayout;
	freeMoveLayout->setAlignment (Qt::AlignTop);
	freeMoveGroupBox->setLayout(freeMoveLayout);
	
	positionLabel = new QLabel("Pos X,Y : 0,0");  
	freeMoveLayout->addWidget(positionLabel);
	
	freeMoveLayout->addWidget(new QLabel("Set Position"));
	freePosXSpinner = new QSpinBox;
	freePosXSpinner->setRange(0, 65535);
    freePosXSpinner->setSingleStep(1);
	freeMoveLayout->addWidget(freePosXSpinner);
	freePosYSpinner = new QSpinBox;
	freePosYSpinner->setRange(0, 65535);
    freePosYSpinner->setSingleStep(1);
	freeMoveLayout->addWidget(freePosYSpinner);
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
}
