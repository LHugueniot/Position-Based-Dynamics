# PPproj
PBD library

Build steps:

	qtcreator on AllPBDLib.pro

To use library:

	include path to in library paths 
	-L(path to dir)/LuHuPBDLib/build/ -lPBDLib 

To use library in code:
	
	create a new solver:
		eg. auto m_solver= new LuHu::solver(1.0f, glm::vec3(0,-0.1,0));
	create new PBDObject and initialize it by passing in the path and name to an obj file:
		eg. auto m_testObj = std::shared_ptr<LuHu::PBDobject>(new LuHu::PBDobject);
		auto a=m_testObj->Initialize("/home/s4906706/Documents/PP/PPproj/LuHuPBDLib/PBDLib/models/plaine.obj",0,glm::vec3(0,5,0));
	(note object must only be comprised of triangles, no quad support yet)

	add the PBDObject to the solver:
		eg. m_solver->addPBDobject(m_testObj);
	Finally in main run loop, run the solver:
		m_solver->RunSolver(5.0f);

	To set immovable point:
		m_testObj->getPoints()[0]->setIM(0)

To use demo:
	In the initialize function it is possible to switch between a cone model and a plain model which have been pre setup.
	
Class Hierarchy is based on this UML diagram:

![LuHuPBDUMLDiagram](https://user-images.githubusercontent.com/22621061/54531231-b13f5180-497c-11e9-95e9-2467184c3e19.png)
