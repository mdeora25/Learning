
vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
    vector<string> answer;
    int num_questions = start;

    for (unsigned idx = 0; idx < created.size(); idx++) {
        if (num_questions >= needed[idx]) {
            answer.push_back("No problem! :D");
             num_questions -= needed[idx];
        }
        else
            answer.push_back("No problem. :(");
        num_questions += created[idx];
    }

    return answer;
}
