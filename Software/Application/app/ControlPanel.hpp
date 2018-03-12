#pragma once


#include "Common.hpp"


class ControlPanel: public QDockWidget
{
	Q_OBJECT
	public:
		QScrollArea* scrollAreaBase;
		QWidget* widgetBase; 
		QVBoxLayout* layoutBase;
		
		//Z Ctrl
		QLabel* labelZCtrl;
		
		QHBoxLayout* layoutConstantHeight;
		QLabel* labelConstantHeight;
		QCheckBox* checkConstantHeight;
		
		QHBoxLayout* layoutTunSetpoint;
		QLabel* labelTunSetpoint; 
		QDoubleSpinBox* spinTunSetpoint;
		
		QPushButton* buttonTunCtrlStartStop;
		
		QHBoxLayout* layoutZValue;
		QLabel* labelZValue; 
		QDoubleSpinBox* spinZValue;
		QPushButton* buttonZMoveTo;
		
		QHBoxLayout* layoutTunStopPoint;
		QLabel* labelTunStopPoint; 
		QDoubleSpinBox* spinTunStopPoint;
		
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

		QPushButton* buttonScanStartStop;
		
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
		
		QPushButton* buttonSetBias;
		
	
		ControlPanel();
};