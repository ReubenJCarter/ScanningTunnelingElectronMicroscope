#include "ControlPanel.hpp"


ControlPanel::ControlPanel(): QDockWidget("Control Panel")
{
	scrollAreaBase = new QScrollArea();
	widgetBase = new QWidget();
	layoutBase = new QVBoxLayout();
	
	widgetBase->setLayout(layoutBase);
	scrollAreaBase->setWidget(widgetBase);
	scrollAreaBase->setWidgetResizable(true);
	setWidget(scrollAreaBase);
	
	layoutBase->setAlignment(Qt::AlignTop);
		
	//Z Ctrl
	labelZCtrl = new QLabel("Z Control");
	labelZCtrl->setStyleSheet("font-weight: bold;");
	layoutBase->addWidget(labelZCtrl); 
		
	QHBoxLayout* layoutConstantHeight = new QHBoxLayout();
	labelConstantHeight = new QLabel("Constant Height");
	checkConstantHeight = new QCheckBox();
	layoutBase->addLayout(layoutConstantHeight); 
	layoutConstantHeight->addWidget(labelConstantHeight);
	layoutConstantHeight->addWidget(checkConstantHeight);
	
	layoutTunSetpoint = new QHBoxLayout();
	labelTunSetpoint = new QLabel("Tunneling Setpoint"); 
	spinTunSetpoint = new QDoubleSpinBox();
	layoutBase->addLayout(layoutTunSetpoint); 
	layoutTunSetpoint->addWidget(labelTunSetpoint); 
	layoutTunSetpoint->addWidget(spinTunSetpoint); 
	
	buttonTunCtrlStartStop = new QPushButton("Start Tunneling Current Ctrlr");
	layoutBase->addWidget(buttonTunCtrlStartStop);
	buttonTunCtrlStartStop->setCheckable(true); 
	connect(buttonTunCtrlStartStop, &QPushButton::clicked, [this]()
	{
		if(buttonTunCtrlStartStop->isChecked())
			buttonTunCtrlStartStop->setText("Stop Tunneling Current Ctrlr");
		else
			buttonTunCtrlStartStop->setText("Start Tunneling Current Ctrlr");
	});
	
	layoutZValue = new QHBoxLayout();
	labelZValue = new QLabel("Z Value"); 
	spinZValue = new QDoubleSpinBox();
	buttonZMoveTo = new QPushButton("Move Tip");
	layoutBase->addLayout(layoutZValue); 
	layoutZValue->addWidget(labelZValue); 
	layoutZValue->addWidget(spinZValue);
	layoutZValue->addWidget(buttonZMoveTo);
	
	layoutTunStopPoint  = new QHBoxLayout();
	labelTunStopPoint = new QLabel("Tunneling Stop Point"); 
	spinTunStopPoint = new QDoubleSpinBox();
	layoutBase->addLayout(layoutTunStopPoint); 
	layoutTunStopPoint->addWidget(labelTunStopPoint); 
	layoutTunStopPoint->addWidget(spinTunStopPoint); 
	
	auto checkConstantHeightLamda = [this](bool checked)
	{
		if(!checked)
		{
			labelTunSetpoint->setVisible(true);
			spinTunSetpoint->setVisible(true); 
			buttonTunCtrlStartStop->setVisible(true); 
			labelZValue->setVisible(false);
			spinZValue->setVisible(false);
			buttonZMoveTo->setVisible(false);
			labelTunStopPoint->setVisible(false);
			spinTunStopPoint->setVisible(false);
		}
		else
		{
			labelTunSetpoint->setVisible(false);
			spinTunSetpoint->setVisible(false); 
			buttonTunCtrlStartStop->setVisible(false); 
			buttonTunCtrlStartStop->setChecked(false); 
			buttonTunCtrlStartStop->setText("Start Tunneling Current Ctrlr");
			labelZValue->setVisible(true);
			spinZValue->setVisible(true);
			buttonZMoveTo->setVisible(true);
			labelTunStopPoint->setVisible(true);
			spinTunStopPoint->setVisible(true);
		}
	};
	connect(checkConstantHeight, &QCheckBox::toggled, checkConstantHeightLamda);
	
	checkConstantHeight->setChecked(true);
	
	//XY Scan 
	labelXYScan = new QLabel("XY Scan"); 
	labelXYScan->setStyleSheet("font-weight: bold;");
	layoutBase->addWidget(labelXYScan); 
	
	layoutScanMin = new QHBoxLayout();
	labelScanMin = new QLabel("Min x/y"); 
	spinScanXMin = new QDoubleSpinBox();
	spinScanYMin = new QDoubleSpinBox();
	layoutBase->addLayout(layoutScanMin); 
	layoutScanMin->addWidget(labelScanMin); 
	layoutScanMin->addWidget(spinScanXMin); 
	layoutScanMin->addWidget(spinScanYMin); 
	
	layoutScanMax = new QHBoxLayout();
	labelScanMax = new QLabel("Max x/y"); 
	spinScanXMax = new QDoubleSpinBox(); 
	spinScanYMax = new QDoubleSpinBox();
	layoutBase->addLayout(layoutScanMax); 
	layoutScanMax->addWidget(labelScanMax); 
	layoutScanMax->addWidget(spinScanXMax); 
	layoutScanMax->addWidget(spinScanYMax); 

	buttonScanStartStop = new QPushButton("Start Scan");
	layoutBase->addWidget(buttonScanStartStop);
	buttonScanStartStop->setCheckable(true);
	
	connect(buttonScanStartStop, &QPushButton::clicked, [this]()
	{
		if(buttonScanStartStop->isChecked())
			buttonScanStartStop->setText("Stop Scan");
		else
			buttonScanStartStop->setText("Start Scan");
	});
	
	//XY Cursor
	labelXYCursor = new QLabel("Cursor"); 
	labelXYCursor->setStyleSheet("font-weight: bold;");
	layoutBase->addWidget(labelXYCursor); 
	
	layoutCursorPosition = new QHBoxLayout();
	labelCursorPosition = new QLabel("position x/y"); 
	spinCursorXMax = new QDoubleSpinBox();
	spinCursorYMax = new QDoubleSpinBox();
	layoutBase->addLayout(layoutCursorPosition); 
	layoutCursorPosition->addWidget(labelCursorPosition); 
	layoutCursorPosition->addWidget(spinCursorXMax); 
	layoutCursorPosition->addWidget(spinCursorYMax); 
	
	buttonCursorMoveTo = new QPushButton("Move Tip");
	layoutBase->addWidget(buttonCursorMoveTo); 
	
	//B Ctrl
	labelBCtrl = new QLabel("Bias Control"); 
	labelBCtrl->setStyleSheet("font-weight: bold;");
	layoutBase->addWidget(labelBCtrl);
	
	
	layoutBValue = new QHBoxLayout();
	labelBValue = new QLabel("Bias Value"); 
	spinBValue = new QDoubleSpinBox();
	layoutBase->addLayout(layoutBValue);
	layoutBValue->addWidget(labelBValue);
	layoutBValue->addWidget(spinBValue);
	
	
	buttonSetBias = new QPushButton("Set Bias");
	layoutBase->addWidget(buttonSetBias);
	
}
