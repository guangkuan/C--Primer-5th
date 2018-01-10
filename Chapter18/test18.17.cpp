////test 1
//namespace Exercise
//{
//    int ivar = 0;
//    double dvar = 0;
//    const int limit = 1000;
//}
//
//int ivar = 0;
//using Exercise::ivar;
//using Exercise::dvar;
//using Exercise::limit;
//
//int main()
//{
//    double dvar = 3.1416;
//    int iobj = limit + 1;
//    ++ivar;
//    ++::ivar;
//    return 0;
//}

////test 2
//namespace Exercise
//{
//    int ivar = 0;
//    double dvar = 0;
//    const int limit = 1000;
//}
//
//int ivar = 0;
//
//int main()
//{
//    using Exercise::ivar;
//    using Exercise::dvar;
//    using Exercise::limit;
//
//    double dvar = 3.1416;
//    int iobj = limit + 1;
//    ++ivar;
//    ++::ivar;
//    return 0;
//}

//test 3
namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;

using namespace Exercise;

int main()
{
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    return 0;
}

////test 4
//namespace Exercise
//{
//    int ivar = 0;
//    double dvar = 0;
//    const int limit = 1000;
//}
//
//int ivar = 0;
//
//int main()
//{
//    using namespace Exercise;
//
//    double dvar = 3.1416;
//    int iobj = limit + 1;
//    ++ivar;
//    ++::ivar;
//    return 0;
//}
