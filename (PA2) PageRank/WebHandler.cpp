#include "WebHandler.h"

WebHandler::WebHandler(int t_lines, int t_iterations)
{
    power_iterations = t_iterations;

    num_pages = t_lines*2;      //the max number of possible pages is twice the number of pages

    web_matrix = new AdjMatrix(num_pages);

    readInput(t_lines);

    num_pages = url_table.size();
    web_matrix->resizeMatrix(num_pages);

    initializeMatrixValues();

    page_ranks.resize(num_pages, 1.0/num_pages);

    matrixTimesVector(power_iterations-1);

    printPageRanks();
}

WebHandler::~WebHandler()
{
    delete web_matrix;
}

void WebHandler::readInput(int t_lines)
{
    string temp_url;
    int from_page;
    int to_page;

    for(int i = 0; i < t_lines; i++)
    {
        //read in first url and store its index, adding it to table if needed
        temp_url = "";
        cin >> temp_url;
        from_page = getUrlIndex(temp_url);
        if(!(from_page >= 0))
        {
            from_page = url_table.size();
            url_table.push_back(temp_url);
        }

        //do same with second url
        temp_url = "";
        cin >> temp_url;
        to_page = getUrlIndex(temp_url);
        if(!(to_page >= 0))
        {
            to_page = url_table.size();
            url_table.push_back(temp_url);
        }

        web_matrix->updateElement(from_page, to_page, 1);
    }
}

//if URL is already in url_table, returns position of the url in the table
//if URL is not in url_table, returns -1
int WebHandler::getUrlIndex(string t_url)
{
    for(int i = 0; i < url_table.size(); i++)
    {
        if(url_table.at(i).compare(t_url) == 0)
        {
            return i;
        }
    }
    return -1;
}

//called after readInput() to update the edges of web_matrix from 1 to 1/out_degree
void WebHandler::initializeMatrixValues()
{
    int out_degree;
    for(int r = 0; r < num_pages; r++)
    {
        out_degree = 0;
        for(int c = 0; c < num_pages; c++)
        {
            if(web_matrix->getElementValue(r, c) != 0)
            {
                out_degree++;
            }
        }
        for(int c = 0; c < num_pages; c++)
        {
            if(web_matrix->getElementValue(r, c) != 0)
            {
                web_matrix->updateElement(r, c, (web_matrix->getElementValue(r, c))/out_degree);
            }
        }
    }
}

//once matrix and rank vector are initialized, this performs matrix multiplication
void WebHandler::matrixTimesVector(int t_iterations)
{
    double col_sum = 0;
    vector<double> temp;

    for(int i = 0; i < t_iterations; i++)
    {
        temp.clear();
        for(int c = 0; c < num_pages; c++)
        {
            col_sum = 0;
            for(int r = 0; r < num_pages; r++)
            {
                col_sum += (web_matrix->getElementValue(r, c))*page_ranks.at(r);
            }
            temp.push_back(col_sum);
        }
        page_ranks = temp;
    }
}

void WebHandler::printPageRanks()
{
    vector<string> output = url_table;

    cout << "\n";

    for(int i = 0; i < num_pages; i++)
    {
        //takes the first 4 characters of the rank (can be adjusted to fit
        //desired precision) and appends it to the corresponding URL
        output.at(i) = output.at(i) + " " + std::to_string(std::floor(page_ranks.at(i)*100+0.5)/100).substr(0,4);
    }

    std::sort(output.begin(), output.end());

    for(int i = 0; i < num_pages; i++)
    {
        cout << output.at(i) << "\n";
    }
}
