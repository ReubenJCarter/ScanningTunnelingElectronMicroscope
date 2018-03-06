#pragma once


#include <QtWidgets/QWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QScrollArea>


class ControlPanel: public QDockWidget
{
	Q_OBJECT
	public:
		QScrollArea* scrollAreaBase;
		QWidget* widgetBase; 
		QVBoxLayout* layoutBase;
		
		//Z Ctrl
		QLabel* labelZCtrl;
		
		QCheckBox* checkConstantHeight;
		
		QHBoxLayout* layoutZSetpoint;
		QLabel* labelZSetpoint; 
		QDoubleSpinBox* spinZSetpoint;
		
		QHBoxLayout* layoutZValue;
		QLabel* labelZValue; 
		QDoubleSpinBox* spinZValue;
		QPushButton* buttonZMoveTo;
		
		QHBoxLayout* layoutZStopPoint;
		QLabel* labelZStopPoint; 
		QDoubleSpinBox* spinZStopPoint;
		
		//XY Scan 
		QLabel* labelXYScan;
		
		QHBoxLayout* layoutScanMin;
		QLabel* labelScanMin;
		QDoubleSpinBox* spinScanXMin; 
		QDoubleSpinBox* spinScanYMin;
		
		QHBoxLayout* layoutScanMax;
		QLabel* labelScanMax;
		QDoubleSpinBox* spinScanXMax; 
		QDoubleSpinBox* spinScanYMax;

		QCheckBox* checkScanStartStop;
		
		//XY Cursor
		QLabel* labelXYCursor;
		
		QHBoxLayout* layoutCursorPosition;
		QLabel* labelCursorPosition;
		QDoubleSpinBox* spinCursorXMax; 
		QDoubleSpinBox* spinCursorYMax;
		
		QPushButton* buttonCursorMoveTo;
		
		//B Ctrl
		QLabel* labelBCtrl;
		
		QHBoxLayout* layoutBValue;
		QLabel* labelBValue; 
		QDoubleSpinBox* spinBValue;
		
		//Measure
		QLabel* labelMeasure;
		
		QLabel* labelTunRead;
		QLabel* labelZRead;
		
		
		/*
		QWidget* infoSection;
		QScrollArea* scrollArea;
		QWidget* root;
		QVBoxLayout* layout;
	
		QGroupBox* connectionGroupBox;
		QVBoxLayout* connectionLayout;
		
		QPushButton* connectDisconnectButton;
		QLabel* connectionStatusLabel;
		
		QGroupBox* scanGroupBox;
		QGridLayout * scanLayout;
		
		QDoubleSpinBox* scanlineSpeedSpinner; 
		QSpinBox* scanStepSpinner;
		QSpinBox* scanPosXSpinner;
		QSpinBox* scanPosYSpinner;
		QSpinBox* scanSizeXSpinner;
		QSpinBox* scanSizeYSpinner;
		QPushButton* startScanButton;
		QPushButton* cancelScanButton;
		
		QGroupBox* freeMoveGroupBox;
		QGridLayout* freeMoveLayout;
		
		QSpinBox* freePosXSpinner;
		QSpinBox* freePosYSpinner;
		QSpinBox* freePosZSpinner;
		QPushButton* setPositionButton;
		
		QGroupBox* scopeParamGroupBox;
		QVBoxLayout* scopeParamLayout;
		
		QDoubleSpinBox* biasVoltageSpinner; 
		QRadioButton* constantCurrentLock;
		QDoubleSpinBox* tunnelingSetPointSpinner;
		QPushButton* setScopeParamButton;
		*/
		ControlPanel();
};