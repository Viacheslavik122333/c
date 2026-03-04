#ifndef IO_STATUS_H
#define IO_STATUS_H

enum class io_status {
    success, // успешное выполнение
    eof, //  достигнут конец файла
    format, // ошибка формата данных
    memory, // ошибка выделения памяти
    open, // ошибка открытия файла
    create, // ошибка создания файла
};

const char* get_error_message(io_status);

#endif // IO_STATUS_H
