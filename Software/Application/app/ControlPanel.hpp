#pragma once


#include <QtWidgets/QWidget>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QScrollArea>


class ControlPanel: public QDockWidget
{
	Q_OBJECT
	public:
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
		
		ControlPanel();
};