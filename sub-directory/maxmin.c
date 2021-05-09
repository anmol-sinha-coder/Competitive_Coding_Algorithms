#include <stdio.h>

void main()
{
    int m, t;
    printf("Enter no. of machines and no. of tasks: ");
    scanf("%d %d", &m, &t);

    register int i;
    register int j;
    int CT[m][t];

    printf("\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < t; ++j)
        {
            scanf("%d", &CT[i][j]);
        }
    }

    printf("\t");
    for (i = 0; i < t; ++i)
    {
        printf("T%d\t", i);
    }
    printf("\n");
    for (i = 0; i < m; ++i)
    {
        printf("M%d\t", i);
        for (j = 0; j < t; ++j)
        {
            printf("%d\t", CT[i][j]);
        }
        printf("\n");
    }

    int ready_time[m],
        task_count = 0,
        assignment[t][2]; // {taskid, machineid}

    for (int i = 0; i < m; i++)
        ready_time[i] = 0;


    for (int m_ = 0; m_ < m; m_++)
        for (int t_ = 0; t_ < t; t_++)
            CT[m_][t_] += ready_time[m_];

    while (task_count < t)
    {
        int task_id,
            machine_id,
            max_val = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < t; j++)
            {

                if (CT[i][j] > max_val)
                {
                    max_val = CT[i][j];
                    task_id = j;
                    machine_id = i;
                }
            }
        }


        assignment[task_count][0] = task_id;
        assignment[task_count++][1] = machine_id;

        ready_time[machine_id] += CT[machine_id][task_id]; // updation of the ready_time for the chosen machine


        for (int t_ = 0; t_ < t; t_++)
            CT[machine_id][t_] += CT[machine_id][task_id];

        for (int m_ = 0; m_ < m; m_++)
            CT[m_][task_id] = -1; // removal of the assigned task
    }

    printf("Following are the assignments:\n");
    for (int i = 0; i < t; i++)
    {
        printf("Task[%d] -> Machine[%d]\n", assignment[i][0], assignment[i][1]);
    }
}
/*
1 4 7 8 9
2 5 8 7 6
3 6 9 5 4
*/
