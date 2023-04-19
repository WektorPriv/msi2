//
// Algorytm budowy drzewa decyzjyjnego MSI
// Created by Wiktor Bystrek on 16.04.2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cmath>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <cmath>
#include <filesystem>
#include <fstream>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

typedef vector<string> vs;
typedef vector<Point2f> vp;
typedef vector<vs> vvs;
typedef vector<int> vi;
typedef map<string, int> msi;
typedef vector<double> vd;

struct node
{
    string splitOn;
    string label;
    bool isLeaf;
    vector<string> childrenValues;
    vector<node*> children;
};

struct figure
{
    string label;
    string cornerCnt;
    string hWRatio;
    string parallelCnt;
    string rAngleCnt;
};

vvs pruneTable(vvs&, string&, const string&);
int returnIndexOfVector(vs&, string);
node* buildDecisionTree(vvs& table, node* nodePtr, vvs& tableInfo);
bool isHomogeneous(vvs&);
vi countDistinct(vvs&, int);
string selectAttribute(vvs&);
int returnColumnIndex(string&, vvs&);
bool tableIsEmpty(vvs&);
void printDecisionTree(node*);
string testDataOnDecisionTree(vs&, node*, vvs&, const string&);
vvs generateTableInfo(vvs& dataTable);
string returnMostFrequentClass(vvs& dataTable);
figure processImage(const string& imageToLearn);
int getRightAnglesCnt(vp corners);
int getParallelCnt(vector<Point2f> corners);
float getAngleABC(Point2f a, Point2f b, Point2f c);
bool comparePoints(Point2f p1, Point2f p2);
double getClockwiseAngle(Point2f p);
void printAttributeTable(vvs &attributeTable);
vp getGoodFeaturesToTrack();
string calculateHWRatio(vp corners);
float distance(Point2f a, Point2f b);
string getFileName(const string& strPath);
vs figureToVS(const figure& fig);
vs getAllFilesNamesWithinFolder(const string& folder);
vs getHeaders();
bool checkIfFileExists(const string& name);
void generateOutputFile(const string& prediction, node* root, vvs& dataTable, const string& filename);
void printDecisionTreeFile(node* nodePtr, ofstream& file);
void printAttributeTableFile(vvs &attributeTable, ofstream& file);
