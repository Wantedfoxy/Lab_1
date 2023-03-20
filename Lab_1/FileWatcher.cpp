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

	m_fileList.append(fileInfo);
	m_fileSizes[fileInfo.filePath()] = fileInfo.size();
	m_isExist[fileInfo.filePath()] = fileInfo.exists();

	emit fileAddedToWatcher(fileInfo.filePath(), m_fileSizes[fileInfo.filePath()]);
}

void FileWatcher::UpdateFileState()
{
    for (int i = 0; i < m_fileList.size(); ++i)
    {
        QFile file(m_fileList[i].filePath());

        if (file.exists() && m_isExist[file.fileName()] == false) {
            m_fileSizes[file.fileName()] = file.size();
            m_isExist[file.fileName()] = true;
            emit fileCreated(file.fileName(), m_fileSizes[file.fileName()]);
        }
        else if (file.exists() && file.size() != m_fileSizes[file.fileName()]) {
            m_fileSizes[file.fileName()] = file.size();
            emit fileModified(file.fileName(), m_fileSizes[file.fileName()]);
        }
        else if (!file.exists() && m_isExist[file.fileName()] == true) {
            m_fileSizes.remove(file.fileName()); // удаление размера файла из m_fileSizes
            m_isExist[file.fileName()] = false;
            emit fileDeleted(file.fileName());
        }
    }
}