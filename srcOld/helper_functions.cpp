#include "helper_functions.h"

LandmarkObs transform(LandmarkObs lm, PosDir posdir) {
  double cost = cos(posdir.theta);
  double sint = sin(posdir.theta);

  return LandmarkObs{
    lm.id,
    posdir.x + (cost * lm.x) - (sint * lm.y),
    posdir.y + (sint * lm.x) + (cost * lm.y)
  };
}

double multivariateGaussian(double x, double y, double mu_x, double mu_y, double sig_x, double sig_y) {
	double expontent = -(pow(x - mu_x, 2) / 2.0 / pow(sig_x, 2) + pow(y - mu_y, 2) / 2.0 / pow(sig_y, 2));
	return exp(expontent) / 2.0 / M_PI / sig_x / sig_y;
}
