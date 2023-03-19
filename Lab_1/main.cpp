#include <QCoreApplication>
#include "filewatcher.h"
#include "consoleoutput.h"

int main(int argc, char* argv[])
{
	// Создаем объект приложения
	QCoreApplication a(argc, argv);
	// Создаем объекты классов FileWatcher и ConsoleOutput
	FileWatcher* watcher = new FileWatcher();
	ConsoleOutput* output = new ConsoleOutput();
	// Устанавливаем соединения между сигналами и слотами
	QObject::connect(watcher, &FileWatcher::fileExists, output, &ConsoleOutput::printFileExistence);
	QObject::connect(watcher, &FileWatcher::fileModified, output, &ConsoleOutput::printFileModification);
	QObject::connect(watcher, &FileWatcher::fileNotExists, output, &ConsoleOutput::printFileNotExists);
	// Добавляем файлы для отслеживания
	watcher->addFile("C:\\files_for_lab_1\\First.txt");
	watcher->addFile("C:\\files_for_lab_1\\Second.txt");
	watcher->addFile("C:\\files_for_lab_1\\Thrid.txt");
	// Создаем объект QTimer и устанавливаем соединение между его сигналом timeout и слотом UpdateFileState класса FileWatcher
	QTimer timer;
	timer.setInterval(2000);
	QObject::connect(&timer, &QTimer::timeout, watcher, &FileWatcher::UpdateFileState);
	timer.start();
	// Запускаем приложение
	return a.exec();
}