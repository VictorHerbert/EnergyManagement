    if (h[1] <= 38.50) {
        if (h[6] <= 3.50) {
            if (h[3] <= 119974.50) {
                if (h[5] <= 3.50) {
                    if (h[1] <= 3.50) {
                        if (h[0] <= 2.50) {
                            return false;
                        } else {
                            if (h[0] <= 59980.00) {
                                return true;
                            } else {
                                return false;
                            }
                        }
                    } else {
                        return false;
                    }
                } else {
                    if (h[1] <= 3.50) {
                        return false;
                    } else {
                        if (h[4] <= 3.50) {
                            if (h[0] <= 59952.00) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                return true;
            }
        } else {
            if (h[5] <= 2.50) {
                if (h[3] <= 3.50) {
                    return false;
                } else {
                    return true;
                }
            } else {
                return false;
            }
        }
    } else {
        if (h[0] <= 38.50) {
            if (h[1] <= 119882.00) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }