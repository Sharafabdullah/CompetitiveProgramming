string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '5')
            s[i] = '9' - s[i] + '0';
    }
    cout << s;