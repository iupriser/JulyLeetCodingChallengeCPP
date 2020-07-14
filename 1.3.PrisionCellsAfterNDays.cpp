class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        set<string> seen;
        int size = 0;
        bool flag = false;
        for (int i = 0; i < N; ++i)
        {

            vector<int> nextState(8, 0);

            for (int j = 1; j < 7; ++j)
            {
                nextState[j] = (cells[j - 1] == cells[j + 1] ? 1 : 0);
            }

            string str;
            for (auto i : nextState)
            {
                str += to_string(i);
            }

            if (seen.find(str) == seen.end())
            {
                seen.insert(str);
                size++;
            }
            else
            {
                flag = true;
                break;
            }
            cells = nextState;
        }

        if (flag)
        {
            N = N % size;
            for (int i = 0; i < N; ++i)
            {
                vector<int> nextState(8, 0);
                for (int j = 1; j < 7; ++j)
                {
                    nextState[j] = (cells[j - 1] == cells[j + 1] ? 1 : 0);
                }
                cells = nextState;
            }
        }

        return cells;
    }
};