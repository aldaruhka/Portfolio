Проекты:

1)pipex
Файлы: Собственная библиотека некторых функций в папке libft. Так же собственная функция get_next_line, и сам проект в основном каталоге. Есть Makefile для сборки проекта
Описание: Проект pipex реализует принцип fork-pipe из командных оболочек. Проект учебный. После сборки проекта запускается следующим образом:
а) ./pipex file1 cmd1 cmd2 ... cmdN file2, где file1 и file2 являются файлами для "чтения из" и "записи в" соответственно, а cmd - команды (можно с аргументами, но надо дополнять кавычками, к примеру "cat -e"). Работает так же, как и аналогичная команда bash из Linux'a "< file1 cmd1 | cmd2 | ... cmdN > file2"
б) ./pipex here_doc LIMITER file1 cmd1 cmd2 ... cmdN file2, где here_doc ключевое слово, а LIMITER - стоп-слово для heredoc. Работает так же, как аналогичная команда bash из Linux'a "<< LIMITER cmd1 | cmd2 | ... cmdN >> file2"

2) Philosophers
Файлы: Две папки с основной и бонусной частью проекта, а так же файл с задачей "en.subject.pdf"
Описание: Реализация классической задачи про обедающих философов на C. 
а) Основная часть написана через треды при помощи мьютексов
б) Бонусная часть написана при помощи fork() + треды, и семафоров.

3) ft_printf
Файды: весь проект в основной папке. Есть Makefile для сборки статичной библиотеки, так как это только функция.
Описание: Функция printf из языка C, реализованная собственноручно. Проект учебный. Сделаны следующие форматы данных: %c, %s, %p, %d, %i, %u, %x, %X, %%. Плюс 3 флага, повторяющие основную функцию: "#", " "(пробел), "+". Для проверок нужна собственная функция main
