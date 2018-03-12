#pragma once

#include "Common.hpp"

#include "ScopeViewer.hpp"
#include "ControlPanel.hpp"
#include "ConsolePanel.hpp"
#include "DevicePanel.hpp"


class MainWindow: public QMainWindow
{
	Q_OBJECT
	public:
		ScopeViewer scopeViewer;
		ControlPanel controlPanel;
		ConsolePanel console;
		DevicePanel devicePanel; 
	
		QMenu* fileMenu;
		QAction* saveAction;
		QAction* loadAction;
		
		MainWindow();
		void ExpandToFitScreen();
		
	public slots:
		void Save();
		void Load();

};