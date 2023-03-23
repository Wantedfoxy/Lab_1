#pragma once
#include <QObject>//Используется для создания пользовательских классов
#include <QFile>//Используется для проверки существования и размера файлов
#include <QFileInfo>//Используется для проверки существования и размера файлов
#include <QList>//Используется для хранения списка файлов, за которыми следит FileWatcher
#include <QMap>//Используется для хранения информации о размере файлов

class FileWatcher : public QObject
{
	Q_OBJECT// Макрос для использования сигналов и слотов
public:
	static FileWatcher* getInstance();
	~FileWatcher();
	void addFile(QString filePath);// Метод для добавления файла в список отслеживаемых файлов
	void deleteFile(QString filename);

signals:
	// Сигналы, которые отправляются при изменении состояния файла или добавлении его в мониторинг
	void fileCreated(std::string filePath, qint64 fileSize);
	void fileDeleted(std::string filePath);
	void fileDeletedFromWatcher(std::string filePath);
	void fileModified(std::string filePath, qint64 fileSize);
	void fileAddedToWatcher(std::string filePath, qint64 fileSize);

public slots:
	void UpdateFileState();// Слот для проверки изменений в файловой системе

private:
	FileWatcher(QObject* parent = nullptr);// Конструктор класса
	static FileWatcher* instance;
	QList<QFileInfo> m_fileList;// Список отслеживаемых файлов
	QMap<QString, QDateTime> m_fileLastModified;// Информация о размере файлов
	QMap <QString, bool> m_isExist; // Переменная, хранящая статус файла на момент последней проверки
};