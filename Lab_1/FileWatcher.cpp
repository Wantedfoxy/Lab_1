#include "FileWatcher.h"
#include "ConsoleOutput.h"

FileWatcher* FileWatcher::instance = nullptr;

FileWatcher* FileWatcher::getInstance()
{
	if (instance == nullptr)
	{
		return instance = new FileWatcher(new QObject());
	}

	return instance;
}

FileWatcher::~FileWatcher()
{};

// Конструктор класса FileWatcher
FileWatcher::FileWatcher(QObject* parent) :
	QObject(parent)
{
}
// Метод добавления файла для отслеживания
void FileWatcher::addFile(QString filePath)
{
	// Создаем объект класса QFileInfo для проверки существования файла
	QFileInfo fileInfo(filePath);

	m_fileList.append(fileInfo);
	m_fileLastModified[fileInfo.filePath()] = fileInfo.lastModified();
	m_isExist[fileInfo.filePath()] = fileInfo.exists();

	emit fileAddedToWatcher(fileInfo.filePath().toStdString(), fileInfo.size());
}

void FileWatcher::deleteFile(QString filePath)
{
	QFileInfo fileInfo(filePath);
	m_fileList.removeOne(fileInfo);
	m_fileLastModified.remove(filePath);
	m_isExist.remove(filePath);
	emit fileDeletedFromWatcher(filePath.toStdString());  //Посылаем сигнал об удалении файла
}

void FileWatcher::UpdateFileState()
{
	// Цикл по всем файлам в списке m_fileList
	for (int i = 0; i < m_fileList.size(); ++i)
	{
		// Создание объекта QFile для текущего файла
		QFileInfo file(m_fileList[i].filePath());
		// Если файл существует и ранее не был зарегистрирован как существующий
		if (file.exists() && !m_isExist[file.filePath()]) {
			m_fileLastModified[file.filePath()] = file.lastModified();// Обновляем дату изменения файла
			m_isExist[file.filePath()] = true;// Регистрируем файл как существующий
			emit fileCreated(file.filePath().toStdString(), file.size());// Имитируем сигнал
		}// Если файл существует и его дата изменения не совпадает с хранимой
		else if (file.exists() && m_fileLastModified[file.filePath()] != file.lastModified()) {
			m_fileLastModified[file.filePath()] = file.lastModified();//Обновляем дату изменения файла
			emit fileModified(file.filePath().toStdString(), file.size());//Имитируем сигнал
		}//Если файл не существует и ранее был зарегистрирован как существующий
		else if (!file.exists() && m_isExist[file.filePath()]) {
			m_fileLastModified.remove(file.filePath());
			m_isExist[file.filePath()] = false;// Регистрируем файл как несуществующий
			emit fileDeleted(file.filePath().toStdString());// Имитируем сигнал
		}
	}
}