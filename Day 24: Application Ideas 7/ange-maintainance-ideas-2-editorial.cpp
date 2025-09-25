using ii = pair<int, int>;
#define F first
#define S second

struct range_maintainance
{
    set<ii> st;
    void fill_range(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= l)
            {
                l = it->first;
                r = max(r, it->second);
                st.erase(it);
            }
        }

        auto it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                r = it->second;
                l = min(r, it->second);
                st.erase(it);
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it == st.end() || (it->second <= r))
            {
                break;
            }
            else
            {
                st.erase(it);
            }
        }

        st.insert({l, r});
    }

    void clear_range(int l, int r)
    {
        auto it = st.upper_bound({l, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo1 = it->first;
                int hi1 = l;

                int lo2 = r;
                int hi2 = it->second;

                st.erase(it);
                st.insert({lo1, hi1});
                st.insert({lo2, hi2});
                return;
            }

            if (it->second >= l)
            {
                int lo = it->first;
                int hi = l;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        it = st.upper_bound({r, 1e9});
        if (it != st.begin())
        {
            it--;
            if (it->second >= r)
            {
                int lo = r;
                int hi = it->second;
                st.erase(it);
                st.insert({lo, hi});
            }
        }

        while (1)
        {
            it = st.lower_bound({l, 0});
            if (it = st.end() || (it->first > r))
            {
                break;
            }
            else
            {
                st.erase(it);
            }
        }
    }

    bool check_point(int x)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= x)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    bool check_range_any(int x, int y)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it != st.end())
        {
            if (it->first <= y)
            {
                return 1;
            }
        }
        return check_point(x);
    }

    bool check_range_all(int x, int y)
    {
        auto it = st.upper_bound({x, 1e9});
        if (it == st.begin())
        {
            return 0;
        }
        else
        {
            it--;
            if (it->second >= y)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
};