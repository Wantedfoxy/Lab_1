#include "ConsoleOutput.h"
// Конструктор класса ConsoleOutput
ConsoleOutput::ConsoleOutput(QObject* parent) : QObject(parent)
{

}
// Метод вывода информации о существующем файле
void ConsoleOutput::printFileExistence(QString filePath, qint64 fileSize)
{
	qDebug() << "File exists:" << filePath << ", size:" << fileSize << "bytes";
}
// Метод вывода информации об изменении существующего файла
void ConsoleOutput::printFileModification(QString filePath, qint64 fileSize)
{
	qDebug() << "Existing file has been modified:" << filePath << ", size:" << fileSize << "bytes";
}
// Метод вывода информации о том, что файла не существует
void ConsoleOutput::printFileNotExists(QString filePath)
{
	qDebug() << "File does not exist:" << filePath;
}