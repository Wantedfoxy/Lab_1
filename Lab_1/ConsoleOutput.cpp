#include "ConsoleOutput.h"

ConsoleOutput* ConsoleOutput::instance = nullptr;

ConsoleOutput* ConsoleOutput::getInstance()
{
	if (instance == nullptr)
	{
		return instance = new ConsoleOutput();
	}

	return instance;
}

ConsoleOutput::~ConsoleOutput()
{
	instance->deleteLater(); // удаляем объект в асинхронном режиме
	instance = nullptr; // устанавливаем указатель на nullptr
};

// Конструктор класса ConsoleOutput
ConsoleOutput::ConsoleOutput(QObject* parent) : QObject(parent)
{}
// Метод вывода информации о существующем файле
void ConsoleOutput::printFileCreated(string filePath, qint64 fileSize)
{
	cout << "File was created: " << filePath << ", size: " << fileSize << "bytes" << endl;
}
//Метод вывода информации о добавлении файла в мониторинг
void ConsoleOutput::printFileAddedToWatcher(string filePath, qint64 fileSize, bool isExist)
{
	if (isExist)
	{
		cout << "File was added to watcher: " << filePath << ", size: " << fileSize << "bytes" << endl;
	}
	else {
		cout << "File was added to watcher: " << filePath << ", It's not exist" << endl;
	}

}
// Метод вывода информации об изменении существующего файла
void ConsoleOutput::printFileModification(string filePath, qint64 fileSize)
{
	cout << "Existing file has been modified: " << filePath << ", size: " << fileSize << "bytes" << endl;
}
// Метод вывода информации о том, что файла не существует
void ConsoleOutput::printFileDeleted(string filePath)
{
	cout << "File was deleted: " << filePath << endl;
}
//Метод вывода информации об удалении файла из мониторинга
void ConsoleOutput::printFileDeletedFromWatcher(string filePath)
{
	cout << "File " << filePath << " was deleted from Watcher" << endl;
}
//Метод вывода информации о том, что файл уже находимтся под мониторингом
void ConsoleOutput::printFileAlreadyAddedToWatcher(string filePath)
{
	cout << "File " << filePath << " has already been added to Watcher" << endl;
}
//Метод вывода информации о том, что такого файла нет под мониторингом
void ConsoleOutput::printNoSuchFileInWatcher(string filePath)
{
	cout << "There is no such file in the Watcher: " << filePath << endl;
}