#include "CarInMemoryRepository.h"
#include "MainWindow.h"
using namespace repository;

QCoreApplication* create_app(int &argc, char* argv[])
{
	for(int i=1; i<argc; i++)
	{
		if (!qstrcmp(argv[i], "-no-gui"))
			return new QCoreApplication(argc, argv);
	}
	return new QApplication(argc, argv);
}

int main(int argc, char *argv[])
{
	QScopedPointer<QCoreApplication> app(create_app(argc, argv));
	CarInMemoryRepository repo;
	MainWindow window(repo);
	window.show();
	return app->exec();
}
