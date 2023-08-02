## Navigation
[1. Brief description](#Description)  
[2. Project structure](#Structure)  
[3. Installation](#Installation)  

<a name="Description"><h2>Brief description</h2></a>  

The program was developed in C++ (std c++20) in the Microsoft Visual Studio 2022 environment under Windows OS.  
The program was carried out taking into account the following terms of reference:  
  
Design a small program in C++ that would implement support of 3D curves hierarchy.  
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified definitions are below). Each curve should be able to return a 3D point and a first derivative (3D vector) per parameter t along the curve.  
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters.  
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.  
4. Populate a second container that would contain only circles from the first container. Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.  
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest.  
6. Compute the total sum of radii of all curves in the second container.  
7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this library.  
8. Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel TBB library).  
  
Requirements to the implementation:  
1. The implementation must use virtual methods.  
2. Has neither explicit memory deallocation nor memory leaks.  
3. Curves must be physically correct (e.g. radii must be positive).  
4. Containers and sorting must be implemented using STL (C++ Standard Template Library).  
5. The implementation may use constructs of C++11 or higher.  
6. The code must compile with any compiler of your choice (gcc, Visual C++, etc).  
  
<a name="Structure"><h2>Project structure</h2></a>  

* [*3DcurvesHierarchy*](https://github.com/1i10/3DcurvesHierarchy/tree/master/3DcurvesHierarchy) - contains an executable file that uses the Curve Library API;  

* [*CurveLibrary*](https://github.com/1i10/3DcurvesHierarchy/tree/master/CurveLibrary) - contains an implementation of the curve hierarchy library;  

* [*3DcurvesHierarchy.sln*](https://github.com/1i10/3DcurvesHierarchy/blob/master/3DcurvesHierarchy.sln) - solution that uses the Curve library API.  
 
*Classes and methods are documented in the code itself*  
  
<a name="Installation"><h2>Installation</h2></a>

1. Upload the project to the local machine using the command  
**git clone https://github.com/1i10/3DcurvesHierarchy.git**  
2. Open the solution file *3DcurvesHierarchy.sln* in MSVS  
3. **!** Build a library of curves. To do this, select the *CurveLibrary* project in the Solution Explorer and build it  
4. After building the curve library, you can run the *3DcurvesHierarchy* project  