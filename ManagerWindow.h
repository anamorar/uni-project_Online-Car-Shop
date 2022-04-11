#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H
#include "ui_ManagerWindow.h"
#include "CarInMemoryRepository.h"
using namespace repository;

namespace Ui
{
	class ManagerWindow;
}
class ManagerWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit ManagerWindow(CarInMemoryRepository repo, QWidget* parent = Q_NULLPTR);

private:
	CarInMemoryRepository m_repo;
	Ui::ManagerWindowClass ui;
	
	QPushButton* display;
};

#endif
