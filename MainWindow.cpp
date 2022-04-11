#include "MainWindow.h"
#include "ManagerWindow.h"

MainWindow::MainWindow(CarInMemoryRepository repo, QWidget* parent) : QMainWindow(parent) { 
	m_repo = repo;
	ui.setupUi(this);

	welcomeText = ui.centralwidget->findChild<QTextBrowser*>("welcomeText");
	clientButton = ui.centralwidget->findChild<QPushButton*>("clientButton");
	managerButton = ui.centralwidget->findChild<QPushButton*>("managerButton");

	connect(managerButton, &QPushButton::clicked, this, &MainWindow::manager);
}

void MainWindow::manager(bool checked)
{
	ManagerWindow* window = new ManagerWindow(m_repo);
	window->show();
	close();
}

void MainWindow::client(bool checked)
{
	
}



