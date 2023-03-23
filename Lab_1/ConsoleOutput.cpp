#include "ConsoleOutput.h"

ConsoleOutput* ConsoleOutput::instance = nullptr;

ConsoleOutput* ConsoleOutput::getInstance()
{
	if (instance == nullptr)
	{
		return instance = new ConsoleOutput(new QObject());
	}

	return instance;
}

ConsoleOutput::~ConsoleOutput()
{};

// Конструктор класса ConsoleOutput
ConsoleOutput::ConsoleOutput(QObject* parent) : QObject(parent)
{}
// Метод вывода информации о существующем файле
void ConsoleOutput::printFileCreated(string filePath, qint64 fileSize)
{
	cout << "File was created: " << filePath << ", size: " << fileSize << "bytes" << endl;
}
//Метод вывода информации о добавлении файла в мониторинг
void ConsoleOutput::printFileAddedToWatcher(string filePath, qint64 fileSize)
{
	cout << "File was added to watcher: " << filePath << ", size: " << fileSize << "bytes" << endl;
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
	cout << "File was deleted: " << filePath << endl;
}