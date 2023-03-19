// Класс для вывода информации о состоянии файлов в консоль
// Наследуется от QObject для работы с сигналами и слотами
// Используется для вывода информации о состоянии файлов в консоль
// Определяет три слота для вывода информации о существовании, изменении и отсутствии файлов в консоль
// Каждый слот принимает путь к файлу и, при необходимости, его размер
// Выводит информацию в консоль с помощью функции qDebug()
// Используется вместе с классом FileWatcher
#pragma once
#include <QObject>
#include <QDebug>

class ConsoleOutput : public QObject
{
	Q_OBJECT

public:
	explicit ConsoleOutput(QObject* parent = nullptr);// Конструктор класса

public slots:
	// Различные методы вывода информации в консоль
	void printFileExistence(QString filePath, qint64 fileSize);
	void printFileModification(QString filePath, qint64 fileSize);
	void printFileNotExists(QString filePath);
};