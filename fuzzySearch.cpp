#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;

int visited[1000];

void init()
{
    for(int i=0; i<1000; i++)
        visited[i] = 0;
}

int checkString(string s1, string s2, int e)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int sub = abs(len1-len2);
    //if(sub > 1)
    //  return 0;
    // if(sub > 1)
    //   return 0;
    int l = min(len1, len2);
    int j=0;
    for(int i=0; i<l; i++)
    {
        if(s1[i] != s2[i])
            j++;
        if(j > e)
            return 0;
    }
    if(abs(len1 - len2) > e)
        return 0;
    return 1;


}


int checkVis(int n)
{
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
            return 0;
    }
    return 1;
}


int main()
{
    vector<string> pq;
    ifstream fin2("token.txt");
    string str2;
    while(fin2>>str2)
    {
        std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        pq.push_back(str2);
    }

    vector<string> flist;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir ("C:\\Users\\moham\\Desktop\\dir")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            //printf ("%s\n", ent->d_name);
            flist.push_back(ent->d_name);
        }
        closedir (dir);
    }
    else
    {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
    int slope;
    cout<<"Insert slope\n";
    cin>>slope;
    slope--;

    for(auto k: flist)
    {
        if(k != "." && k != "..")
            //cout<<i<<endl;
        {

            int sl = 0;
            int flag = 0;
            init();
            int ctr=0;
            int inst=0;
            int offset=5;


            string f = "C:\\Users\\moham\\Desktop\\dir\\" + k;
            cout<<endl<<f<<endl;
            ifstream fin(f);
            vector<string> words;
            words.clear();
            string str;
            while(fin>>str)
            {
                std::transform(str.begin(), str.end(), str.begin(), ::tolower);
                words.push_back(str);
            }
            init();
            int myc=0;
            for(auto i: words)
            {

                int u=0, fnd;
                for(auto m: pq)
                {

                    fnd = checkString(m, i, 1);
                    //cout<<fnd<<" "<<u<<endl;
                    if(fnd == 1)
                        break;
                    u++;

                }
                //cout<<endl;
                if((fnd == 0))
                {
                    //cout<<"Desired string not found\n";
                    //cout<<sl<<endl;
                    if(sl < slope)
                    {
                        if(flag == 1)
                            sl++;
                    }

                    else
                    {
                        //cout<<"Slope length exceeded\n";
                        init();
                        sl = 0;
                        flag = 0;
                        //return 0;
                    }
                }

                /*    else if(visited[u] != 0)
                    {
                        visited[u] = ctr;
                        sl = 0;
                    }*/


                else if(fnd == 1)
                {
                    flag = 1;
                    visited[u] = ctr;
                    sl = 0;
                }
                //cout<<it - token.begin();
                //cout<<i<<endl;
                if(checkVis(pq.size()))
                {
                    myc++;
                    cout<<endl;
                    int strt, ending, minEl=INT_MAX, maxEl=-1;
                    for(int i=0; i<pq.size(); i++)
                    {
                        //cout<<visited[i]<<endl;
                        if(visited[i] <= minEl)
                            minEl = visited[i];
                        if(visited[i] >= maxEl)
                        {
                            maxEl = visited[i];
                        }
                    }
                    //cout<<minEl<<" "<<maxEl<<endl;
                    //int minEl = min_element(visited, visited + 3);
                    /*if(minEl - offset < 0)
                    {
                        strt = 0;
                    }
                    int wrdSize = words.size();
                    //cout<<wrdSize<<endl;

                    //int maxEl = min_element(visited, visited + 3);
                    if(maxEl + offset > wrdSize - 1)
                    {
                        ending = wrdSize-1;
                    }*/
                    //cout<<strt<<" "<<ending<<endl;
                    int st = minEl - 5;
                    int ed = maxEl + 5;
                    //cout<<st<<endl;
                    for(int i=st; i<=ed; i++)
                    {
                        vector<string>::iterator it;
                        it = find(pq.begin(), pq.end(), words[i]);
                        if(it == pq.end())
                            cout<<words[i]<<" ";
                        else
                            cout<<"<em>"<<words[i]<<"</em> ";
                    }
                    cout<<endl;

                    /* cout<<"desired String found\n";
                     cout<<"String Word"<<setw(15)<<" Position of word occurence\n";
                     int j=0;
                     for(auto q: pq)
                     {
                         cout<<q<<setw(7)<<visited[j]+1<<endl;
                         j++;
                     }*/
                    init();
                    sl = 0;
                    flag = 0;
                    inst++;
                    //break;
                }

                ctr++;

            }
        if(myc == 0)
            cout<<"Not in this file\n";
        }

        cout<<endl;
    }

    return 0;
}
