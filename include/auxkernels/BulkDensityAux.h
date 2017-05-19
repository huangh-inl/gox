/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*                        GOX                                   */
/*                                                              */
/*           (c) 2015 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef BULKDENSITYAUX_H
#define BULKDENSITYAUX_H

#include "AuxKernel.h"


//Forward Declarations
class BulkDensityAux;

/**
 * validParams returns the parameters that this Kernel accepts / needs
 * The actual body of the function MUST be in the .C file.
 */
template<>
InputParameters validParams<BulkDensityAux>();

/**
 * Define the AuxKernel for the kinetic mineral species concentrations
 * according to transient state theory rate law.
 */
class BulkDensityAux : public AuxKernel
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  BulkDensityAux(const InputParameters & parameters);

  virtual ~BulkDensityAux() {}

protected:
  /**
   * Conputes the kinetic mineral sepecies concentration.
   * @return The concentration of a kinetic mineral species.
   */
  virtual Real computeValue();

//   /// Equilibrium constant at reference temperature
//   Real _log_k;
//   /// Specific reactive surface area, m^2/L solution
//   Real _reactive_surface_area;
//   /// Reference kinetic rate constant
//   Real _ref_kconst;
//   /// Activation energy
//   Real _e_act;
//   /// Gas constant, 8.314 J/mol/K
//   Real _gas_const;
//   /// Reference temperature
//   Real _ref_temp;
//   /// Actual system temperature
//   Real _sys_temp;
  /// Stochiometric coefficients for involved primary species
//  std::vector<Real> _sto_v;
  
  const MaterialProperty<Real> & _SA;
  const MaterialProperty<Real> & _k_eff;


  /// Coupled primary species concentrations
  std::vector<const VariableValue *> _vals;

  
  
};

#endif //BULKDENSITYAUX_H
