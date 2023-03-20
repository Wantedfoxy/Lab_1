#include "ConsoleOutput.h"
// Конструктор класса ConsoleOutput
ConsoleOutput::ConsoleOutput(QObject* parent) : QObject(parent)
{

}
// Метод вывода информации о существующем файле
void ConsoleOutput::printFileCreated(QString filePath, qint64 fileSize)
{
	qDebug() << "File was created:" << filePath << ", size:" << fileSize << "bytes";
}
//Метод вывода информации о добавлении файла в мониторинг
void ConsoleOutput::printfileAddedToWatcher(QString filePath, qint64 fileSize)
{
	qDebug() << "File was added to watcher:" << filePath << ", size:" << fileSize << "bytes";
}
// Метод вывода информации об изменении существующего файла
void ConsoleOutput::printFileModification(QString filePath, qint64 fileSize)
{
	qDebug() << "Existing file has been modified:" << filePath << ", size:" << fileSize << "bytes";
}
// Метод вывода информации о том, что файла не существует
void ConsoleOutput::printFileDeleted(QString filePath)
{
	qDebug() << "File was deleted:" << filePath;
}