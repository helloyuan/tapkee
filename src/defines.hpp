#ifndef libedrt_defines
#define libedrt_defines

#include <vector>
#include <string>
#include <map>
#include "utils/any.hpp"
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Sparse>

template<bool> struct basic_static_assert
{
	basic_static_assert();
};

template<> struct basic_static_assert<true>
{
	basic_static_assert()
	{
	}
};

#define STATIC_ASSERT(cond, msg) \
{ \
	class ERROR_##msg {}; \
	(void)sizeof(basic_static_assert<(cond != 0)>(ERROR_##msg()));\
}

template<class PairwiseCallback>
struct CallbackTraits
{
};

enum EDRT_METHOD
{
	KERNEL_LOCALLY_LINEAR_EMBEDDING,
	NEIGHBORHOOD_PRESERVING_EMBEDDING,
	KERNEL_LOCAL_TANGENT_SPACE_ALIGNMENT,
	LINEAR_LOCAL_TANGENT_SPACE_ALIGNMENT,
	HESSIAN_LOCALLY_LINEAR_EMBEDDING,
	LAPLACIAN_EIGENMAPS,
	LOCALITY_PRESERVING_PROJECTIONS,
	DIFFUSION_MAPS,
	ISOMAP,
	MULTIDIMENSIONAL_SCALING,
	STOCHASTIC_PROXIMITY_EMBEDDING,
	MAXIMUM_VARIANCE_UNFOLDING
};

enum EDRT_PARAMETERS
{
	REDUCTION_METHOD,
	NUMBER_OF_NEIGHBORS,
	TARGET_DIMENSIONALITY,
	CURRENT_DIMENSIONALITY
};

typedef Eigen::Triplet<double> SparseTriplet;
typedef std::vector<SparseTriplet> SparseTriplets;
typedef Eigen::MatrixXd DenseMatrix;
typedef Eigen::VectorXd DenseVector;
typedef std::vector<int> LocalNeighbors;
typedef std::vector<LocalNeighbors> Neighbors;
typedef Eigen::SparseMatrix<double> WeightMatrix;
typedef Eigen::MatrixXd EmbeddingMatrix;
typedef std::map<EDRT_PARAMETERS, any> ParametersMap;

/*
struct edrt_options_t
{
	edrt_options_t()
	{
		method = KERNEL_LOCAL_TANGENT_SPACE_ALIGNMENT;
		num_threads = 1;
		use_arpack = true;
		use_superlu = true;
		mds_use_landmarks = false;
		klle_reconstruction_shift = 1e-3;
		diffusion_maps_t = 1;
		nullspace_shift = 1e-9;
	}
	// EDRT method
	EDRT_METHOD method;
	// number of threads
	int num_threads;
	// true if ARPACK should be used
	bool use_arpack;
	// true if SuperLU should be used
	bool use_superlu;
	// mds use landmarks
	bool mds_use_landmarks;
	// kernel LLE reconstruction shift
	double klle_reconstruction_shift;
	// diffusion maps t
	int diffusion_maps_t;
	// nullspace regularization shift
	double nullspace_shift;
};
*/

#endif