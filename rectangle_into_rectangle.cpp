vector<string> rectangle_into_rectangle(int len, int width)
    {
        vector<string> res;

        while (len != width)
        {
            if (len < width)
                swap(len, width);

            res.push_back("(" + to_string(len) + "*" + to_string(width) + ")");
            int count = len / width;
            while (count > 1)
            {
                if(width*count!=len)
                    res.push_back("(" + to_string(width*count) + "*" + to_string(width) + ")");
                count--;
            }
            len -= width;
        }
        return res;
    }
