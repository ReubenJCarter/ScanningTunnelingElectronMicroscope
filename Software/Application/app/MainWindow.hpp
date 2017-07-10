#pragma once


#include "ScopeViewer.hpp"
#include "ControlPanel.hpp"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenuBar>


class MainWindow: public QMainWindow
{
	Q_OBJECT
	public:
		ScopeViewer scopeViewer;
		ControlPanel controlPanel;
	
		QMenu* fileMenu;
		QAction* saveAction;
		QAction* loadAction;
		
		MainWindow();
		void ExpandToFitScreen();
		void Save();
		void Load();

};