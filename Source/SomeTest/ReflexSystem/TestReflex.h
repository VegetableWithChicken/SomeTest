#pragma once
#define OFF_REFLEXACTOR 1

#if OFF_REFLEXACTOR
#include "GameFramework/Actor.h"
#include "ReflexActor.generated.h"
class AReflexActor : public AActor
{
	//GENERATED_BODY()
	// This pair of macros is used to help implement GENERATED_BODY() and GENERATED_USTRUCT_BODY()
	//#define BODY_MACRO_COMBINE_INNER(A,B,C,D) A##B##C##D
	//#define BODY_MACRO_COMBINE(A,B,C,D) BODY_MACRO_COMBINE_INNER(A,B,C,D)

	// Include a redundant semicolon at the end of the generated code block, so that intellisense parsers can start parsing
	// a new declaration if the line number/generated code is out of date.
	//#define GENERATED_BODY_LEGACY(...) BODY_MACRO_COMBINE(CURRENT_FILE_ID,_,__LINE__,_GENERATED_BODY_LEGACY);
	//#define GENERATED_BODY(...) BODY_MACRO_COMBINE(CURRENT_FILE_ID,_,__LINE__,_GENERATED_BODY);
	//CURRENT_FILE_ID��generated�ļ����ң�__LINE__����
	//SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_GENERATED_BODY//��һ�κ��滻�������

//2
//////////////////////////////////////////////////////////////////////////////////////
//public:
//	SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_PRIVATE_PROPERTY_OFFSET//��
//	SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_SPARSE_DATA//��
//	SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS//��
//	SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_INCLASS_NO_PURE_DECLS
//	SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_ENHANCED_CONSTRUCTORS

//3
//////////////////////////////////////////////////////////////////////////////////////
//SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_INCLASS_NO_PURE_DECLSչ��
private:
	//ע��C++ԭ�������Ա㱩¶����ͼ�����ʹ��
	static void StaticRegisterNativesAReflexActor();

	//Ϊ�˹�����Ӧ��UClass ,��һ����������
	friend struct Z_Construct_UClass_AReflexActor_Statics;
public:
	//��������
	//TEXT("/Script/SomeTest") �������ڵİ��� ��ʾ�ýű��߼���SomeTest���棨����C++ �� ��ͼ��
	//NO_API ���ջ����Ϊexe ���Բ���Ҫ������
	//DECLARE_CLASS(AReflexActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SomeTest"), NO_API)չ��
private:
	AReflexActor& operator=(AReflexActor&&);  
	AReflexActor& operator=(const AReflexActor&);  
	NO_API static UClass* GetPrivateStaticClass();
public: 
	/** Bitwise union of #EClassFlags pertaining to this class.*/
	//�������ص�#EClassFlags������������
	//C++ Native�� Ϊ�˺���ͼ���涯̬��������
	//0 ���Ϊ�����κ�����
	enum { StaticClassFlags = (0 | CLASS_Config & ~(CLASS_Intrinsic)) };

	/** Typedef for the base class ({{ typedef-type }}) */
	typedef AActor Super;

	/** Typedef for {{ typedef-type }}. */ 
	typedef AReflexActor ThisClass; 

	/** Returns a UClass object representing this class at runtime */ 
	//��Runtimeģʽ�·������������������
	inline static UClass* StaticClass() 
	{ 
		return GetPrivateStaticClass(); 
	} 

	/** Returns the package this class belongs in */ 
	//��������������pak
	inline static const TCHAR* StaticPackage() 
	{ 
		return TEXT("/Script/SomeTest"); \
	} 

	/** Returns the static cast flags for this class */ 
	//���������ı�־
	inline static EClassCastFlags StaticClassCastFlags() 
	{ 
		return CASTCLASS_None;
	} 

	/** For internal use only; use StaticConstructObject() to create new objects. */ 
	//�����ڲ�ʹ�� ͨ��StaticConstructObject()ȥ����һ���µ�Objects
	inline void* operator new(const size_t InSize, EInternal InInternalOnly, UObject* InOuter = (UObject*)GetTransientPackage(), FName InName = NAME_None, EObjectFlags InSetFlags = RF_NoFlags) 
	{ 
		return StaticAllocateObject(StaticClass(), InOuter, InName, InSetFlags); 
	} 

	/** For internal use only; use StaticConstructObject() to create new objects. */ 
	//�����ڲ�ʹ�� ͨ��StaticConstructObject()ȥ����һ���µ�Objects
	inline void* operator new(const size_t InSize, EInternal* InMem) 
	{ 
		return (void*)InMem; 
	}

	//DECLARE_SERIALIZER(AReflexActor)չ��
	//���л��Լ�
	friend FArchive &operator<<(FArchive& Ar, AReflexActor*& Res) 
	{ 
		return Ar << (UObject*&)Res; 
	}

	friend void operator<<(FStructuredArchive::FSlot InSlot, AReflexActor*& Res) 
	{ 
		InSlot << (UObject*&)Res; 
	}

//SomeTest_Source_SomeTest_ReflexSystem_ReflexActor_h_12_ENHANCED_CONSTRUCTORSչ��
private:
	/** Private move- and copy-constructors, should never be used */
	NO_API AReflexActor(AReflexActor&&);
	NO_API AReflexActor(const AReflexActor&);
public:
	//DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AReflexActor);չ��
	/** DO NOT USE. This constructor is for internal usage only for hot-reload purposes. */
	//����ʹ�á��˹��캯�������ڲ�ʹ�ã�����hot-reloadΪĿ�ġ�
	//����ר�������ع��캯���������ࡣ
	NO_API AReflexActor(FVTableHelper& Helper);

	//DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AReflexActor);չ��
	static UObject* __VTableCtorCaller(FVTableHelper& Helper) 
	{ 
		return new (EC_InternalUseOnlyConstructor, (UObject*)GetTransientPackage(), NAME_None, RF_NeedLoad | RF_ClassDefaultObject | RF_TagGarbageTemp) AReflexActor(Helper); 
	}
	//DEFINE_DEFAULT_CONSTRUCTOR_CALL(AReflexActor)չ��
	//FObjectInitializer ����������C++���캯�������UObject����(��ʼ������)���ڲ��ࡣ
	//���캯����װ�� �������ַ��䴴�������ʱ����Ҫ���ø���Ĺ��캯��
	//��Ӧ UCalss 	typedef void		(*ClassConstructorType)				(const FObjectInitializer&);
	static void __DefaultConstructor(const FObjectInitializer& X) 
	{ 
		//GetObj() ����󣬴Ӿ�̬��������ʼ������
		//EInternal �����ڲ�ʹ�õĹ��캯��
		new((EInternal*)X.GetObj())AReflexActor;
	}



////////////////////////////////////////////////////////////////////////////////////
public:
	// Sets default values for this actor's properties
	AReflexActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

#endif