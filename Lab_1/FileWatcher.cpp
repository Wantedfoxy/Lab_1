#include "FileWatcher.h"
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
	// Если файл не существует, генерируем сигнал fileNotExists и выходим из метода
	if (!fileInfo.exists()) {
		emit fileNotExists(filePath);
		return;
	}

	m_fileList.append(fileInfo);

	if (m_fileSizes.value(filePath, -1) == -1) { // Если размер файла неизвестен
		m_fileSizes.insert(filePath, fileInfo.size()); // Запоминаем размер файла
		emit fileExists(filePath, fileInfo.size()); // Сигнализируем о появлении файла
	}
}
// Работает некорректно, необходима доработка
void FileWatcher::UpdateFileState()
{
	for (const auto& fileInfo : m_fileList)
	{
		if (!fileInfo.exists())// Если файл не существует
		{
			emit fileNotExists(fileInfo.filePath());// Отправляем сигнал о прекращении его существования
		}
		else
		{
			if (fileInfo.size() != m_fileSizes[fileInfo.filePath()])// Если размер файла изменился
			{
				m_fileSizes[fileInfo.filePath()] = fileInfo.size();// Обновляем размер в QMap
				emit fileModified(fileInfo.filePath(), fileInfo.size());// Отправляем сигнал об изменении размера
			}
			else// Если размер не изменился
			{
				emit fileExists(fileInfo.filePath(), fileInfo.size());// Отправляем сигнал о том, что файл существует
			}
		}
	}
}