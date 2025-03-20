#ifndef TASK_H
#define TASK_H
#include <string>

enum class Priority {
    LOW,
    MID,
    HIGH,
    URGENT
};
enum class Status {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
};
class Task {
    std::string m_task_id;
    std::string m_uid;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    int m_prio;
    bool m_status;
public:
    Task();
    Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority);
    Task(const Task& other);
    Task(Task&& other) noexcept;
    ~Task();

    std::string getTitle();

    void edit(const Task& updated_task);
    void set_status(Status status);
    void set_prio(Priority prio);
    void display_info() const;
    int get_task_id() const;

    Task& operator=(const Task& other);
    Task& operator=(Task&& other) noexcept;

    bool operator==(const Task& other) const;
    bool operator!=(const Task& other) const;

    bool operator>(const Task& other) const;
    bool operator<(const Task& other) const;

    Task& operator++(); //this e unenalu
    Task operator++(int);

    Task& operator--();
    Task operator--(int);

};
#endif