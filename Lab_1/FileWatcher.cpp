﻿#include "FileWatcher.h"
#include "ConsoleOutput.h"
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
	m_fileSizes[fileInfo.filePath()] = fileInfo.size();
	m_isExist[fileInfo.filePath()] = fileInfo.exists();

	emit fileAddedToWatcher(fileInfo.filePath(), m_fileSizes[fileInfo.filePath()]);
}

void FileWatcher::UpdateFileState()
{
	// Цикл по всем файлам в списке m_fileList
	for (int i = 0; i < m_fileList.size(); ++i)
	{
		// Создание объекта QFile для текущего файла
		QFile file(m_fileList[i].filePath());
		// Если файл существует и ранее не был зарегистрирован как существующий
		if (file.exists() && m_isExist[file.fileName()] == false) {
			m_fileSizes[file.fileName()] = file.size();// Обновляем размер файла
			m_isExist[file.fileName()] = true;// Регистрируем файл как существующий
			emit fileCreated(file.fileName(), m_fileSizes[file.fileName()]);// Отправляем сигнал
		}// Если файл существует и его размер изменился
		else if (file.exists() && file.size() != m_fileSizes[file.fileName()]) {
			m_fileSizes[file.fileName()] = file.size();//Обновляем размер файла
			emit fileModified(file.fileName(), m_fileSizes[file.fileName()]);//Отправляем сигнал
		}//Если файл не существует и ранее был зарегистрирован как существующий
		else if (!file.exists() && m_isExist[file.fileName()] == true) {
			m_fileSizes.remove(file.fileName()); // удаление размера файла из m_fileSizes
			m_isExist[file.fileName()] = false;// Регистрируем файл как несуществующий
			emit fileDeleted(file.fileName());// Отправляем сигнал
		}
	}
}