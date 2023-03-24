# Lab_1

FileWatcher
Данный репозиторий создан для выполнения лабораторной работы по предмету "Технология разработки программного обеспечения"
Суть лабораторной работы заключается в создании программы, которая будет следить за состояниями нескольких файлов и уведомлять о том, что с ним происходит,
будь то удаление, изменение или создание.

<h2>Постановка задачи:</h2>

Программа будет выводить на консоль уведомление о произошедших изменениях в файле.
Существует несколько ситуаций для наблюдаемого файла

1. Файл существует , файл не  пустой - на экран выводится факт существования файла и его  размер.
2. Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер.  
3. Файл не существует - на экран выводится информация о том что файл не существует.

В главной программе создается объект для отслеживания состояния конкретного файла/файлов, обновление сведений о файле реализуется через таймер.

<h2>Как установить проект</h2>

1. Установить QT версии 5.6.3 и выше
2. Установить Visual Studio 2020 или более новый
3. Настроить QT в Visual Studio
4. Создать Qt Console Application
5. Скопировать код из репозитория и разместить его в своем проекте, готово!

<h2>Диаграмма классов</h2>

![image](https://user-images.githubusercontent.com/50704060/227574449-8972bfaf-b049-4929-8497-5ad22fda5fa4.png)

