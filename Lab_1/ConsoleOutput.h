// Класс для вывода информации о состоянии файлов в консоль
// Наследуется от QObject для работы с сигналами и слотами
// Используется для вывода информации о состоянии файлов в консоль
// Определяет три слота для вывода информации о существовании, изменении и отсутствии файлов в консоль
// Каждый слот принимает путь к файлу и, при необходимости, его размер
// Выводит информацию в консоль с помощью функции qDebug()
// Используется вместе с классом FileWatcher
#pragma once
#include <QObject>
#include <Iostream>

using namespace std;

class ConsoleOutput : public QObject
{
	Q_OBJECT

public:
	explicit ConsoleOutput(QObject* parent = nullptr);// Конструктор класса

public slots:
	// Различные методы вывода информации в консоль
	void printFileAddedToWatcher(string filePath, qint64 fileSize);
	void printFileCreated(string filePath, qint64 fileSize);
	void printFileModification(string filePath, qint64 fileSize);
	void printFileDeleted(string filePath);
	void printFileDeletedFromWatcher(string filePath);
};