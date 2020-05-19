    #include<bits/stdc++.h>
    using namespace std;

    int main() {
        int t;
        cin>>t;
        while(t--) {
            string s;
            cin>>s;
            stack<pair<char,int>>st;
            st.push({s[0],1});
            for(int i = 1;i<s.size();i++) {
                if(!st.empty()) {
                if(st.top().first == s[i]) {
                    st.top().second += 1;
                }
                else if(st.top().second >=3) {
                    st.pop();
                }
                else {
                    st.push({s[i],1});
                }
                           
                }
                else {
                        st.push({s[i],1});
                    }
                
            }
        string ans = "";
        while(!st.empty()) {
            pair<char,int>temp = st.top();
            st.pop();
            ans += temp.first;
        }
        reverse(ans.begin(),ans.end());

        cout<<ans<<endl;
        }
    
    }