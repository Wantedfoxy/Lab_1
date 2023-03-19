#pragma once
#include <QObject>//Используется для создания пользовательских классов
#include <QTimer>//Используется для вызова функций с заданной периодичностью
#include <QFile>//Используется для проверки существования и размера файлов
#include <QFileInfo>//Используется для проверки существования и размера файлов
#include <QList>//Используется для хранения списка файлов, за которыми следит FileWatcher
#include <QMap>//Используется для хранения информации о размере файлов

class FileWatcher : public QObject
{
	Q_OBJECT// Макрос для использования сигналов и слотов
public:
	explicit FileWatcher(QObject* parent = nullptr);// Конструктор класса

	void addFile(QString filePath);// Метод для добавления файла в список отслеживаемых файлов

signals:
	// Сигналы, которые отправляются при изменении состояния файла
	void fileExists(QString filePath, qint64 fileSize);
	void fileNotExists(QString filePath);
	void fileModified(QString filePath, qint64 fileSize);

public slots:
	void UpdateFileState();// Слот для проверки изменений в файловой системе

private:
	QTimer timer;// Таймер для вызова метода UpdateFileState()
	QList<QFileInfo> m_fileList;// Список отслеживаемых файлов
	QMap<QString, qint64> m_fileSizes;// Информация о размере файлов
};