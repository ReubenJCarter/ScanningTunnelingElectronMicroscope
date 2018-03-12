
set (stmAppSrc 
		StmApp.cpp
		MainWindow.cpp
		ControlPanel.cpp
		ScopeViewer.cpp
		ConsolePanel.cpp
		DevicePanel.cpp
)

add_executable(stmApp ${stmAppSrc})

#target_link_libraries(stmApp debug Qt5Cored optimized Qt5Core)
#target_link_libraries(stmApp debug Qt5Guid optimized Qt5Gui)
#target_link_libraries(stmApp debug Qt5Widgetsd optimized Qt5Widgets)
#target_link_libraries(stmApp debug Qt5Chartsd optimized Qt5Charts)
#target_link_libraries(stmApp debug Qt5OpenGLd optimized Qt5OpenGL)

qt5_use_modules(stmApp Widgets Core Gui Charts OpenGL)