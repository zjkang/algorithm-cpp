// convert strings to integers
int stringToInteger(const string& str) {
  istringstream iss(str);
  int result; char remain;
  if (!(iss >> result) || (iss >> remain)) {
    throw domain_error();
  }
  return result;
}

//
