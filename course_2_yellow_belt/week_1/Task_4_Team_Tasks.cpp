#include <map>
#include <string>
#include <iostream>

/////////////////////////////////////////////////////////
///    Реализуйте класс TeamTasks, позволяющий хранить статистику по статусам задач команды разработчиков:
///    Метод PerformPersonTasks должен реализовывать следующий алгоритм :
///
///    1. Рассмотрим все невыполненные задачи разработчика person. 
///    2. Упорядочим их по статусам : 
///    сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и, наконец, 
///    задачи в статусе TESTING. 
///    3. Рассмотрим первые task_count задач и переведём каждую из них в следующий статус
///    в соответствии с естественным порядком : NEW → IN_PROGRESS → TESTING → DONE.
///    4. Вернём кортеж из двух элементов : информацию о статусах обновившихся задач 
///    (включая те, которые оказались в статусе DONE) и информацию о статусах остальных не
///    выполненных задач. 
///    
///    В случае отсутствия разработчика с именем person метод 
///    PerformPersonTasks должен вернуть кортеж из двух пустых TasksInfo
///
///                                                                                                                                                                                                                                                
///    Гарантируется, что task_count является положительным числом. Если task_count превышает текущее 
///    количество невыполненных задач разработчика, достаточно считать, что task_count равен количеству 
///    невыполненных задач : дважды обновлять статус какой - либо задачи в этом случае не нужно.
///
///    Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика, не имеющего задач.
///
///    Ни один из словарей не должен содержать лишних элементов,vто есть статусов, которым соответствует ноль задач.
///
///    По условию, DONE задачи не нужно возвращать в необновлённых задачах(untouched_tasks).
///
///    Примечание: Обновление словаря одновременно с итерированием по нему может привести к непредсказуемым последствиям.
///    При возникновении такой необходимости рекомендуется сначала в отдельном временном словаре собрать информацию об обновлениях,
///    а затем применить их к основному словарю.
///
                                                                                                                          
using namespace std;

enum class TaskStatus
{
    NEW,         // новая
    IN_PROGRESS, // в разработке
    TESTING,     // на тестировании
    DONE         // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        return m_team.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person)
    {
        ++m_team[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string &person, int task_count)
    {
        if (!m_team.count(person))
            return {{}, {}};

        auto& personsTasks = m_team[person];
        TasksInfo updatedTasks, notUpdatedTasks;
        
        for (const auto [status, count] : personsTasks)
        {
            if (status == TaskStatus::DONE)
                break;
                
            if (task_count <= 0)
            {
                notUpdatedTasks[status] = count;
                continue;
            }

            if (task_count >= count)
            {
                task_count -= count;
                updatedTasks[static_cast<TaskStatus>(static_cast<int>(status) + 1)] += count;
            }
            else
            {
                updatedTasks[static_cast<TaskStatus>(static_cast<int>(status) + 1)] += task_count;
                notUpdatedTasks[status] = count - task_count;
                task_count = 0;
            }
        }

        TasksInfo newTasksInfo;
        if (const auto doneTasks = personsTasks[TaskStatus::DONE])
        {
            newTasksInfo[TaskStatus::DONE] = doneTasks;
        }
            
        for (const auto& [status, count] : updatedTasks)
        {
            newTasksInfo[status] += count;
        }
        for (const auto &[status, count] : notUpdatedTasks)
        {
            newTasksInfo[status] += count;
        }

        m_team[person] = std::move(newTasksInfo);

        return {updatedTasks, notUpdatedTasks};
    }

private:
    map<string, TasksInfo> m_team;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info)
{
    cout << tasks_info[TaskStatus::NEW] << " new tasks"
         << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
         << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
         << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
    TeamTasks tasks;
    for (int i = 0; i < 5; ++i)
    {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 5);
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 5);
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 1);
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    for (int i = 0; i < 5; ++i)
    {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    return 0;
}