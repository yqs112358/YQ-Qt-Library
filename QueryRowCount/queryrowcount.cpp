#include "queryrowcount.h"

int queryRowCount(QSqlQuery &query)
{
    int lastPos=query.at();

    int pos=0;
    if (query.last())
        pos=query.at()+1;
    else
        pos=0;

    query.seek(lastPos);
    return pos;
}
