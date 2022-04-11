#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_MainWindow.h"
#include "CarInMemoryRepository.h"
using namespace repository;

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(CarInMemoryRepository repo, QWidget *parent = Q_NULLPTR);
private:
	Ui::MainWindowClass ui;
	CarInMemoryRepository m_repo;

	QTextBrowser* welcomeText;
	QPushButton* clientButton;
	QPushButton* managerButton;

public slots:
	void manager(bool checked = false);
	void client(bool checked = false);
};

#endif

