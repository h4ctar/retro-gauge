$fn=64;
overlap=0.001;

inner_height=40;
inner_radius=43.5;
wall_thickness=6.5;
base_thickness=4;

standoff_height=2;
standoff_outer_radius=3;

pcb_mounting_hole_radius=1.5;

difference() {
    union() {
        difference() {
            // The main body
            cylinder(inner_height + base_thickness, inner_radius + wall_thickness, inner_radius + wall_thickness);
            // The hole in the middle
            translate([0, 0, base_thickness]) {
                cylinder(inner_height + overlap, inner_radius, inner_radius);
            };
        };
        // The PCB standoffs
        translate([-33.78, 19.2, 0]) {
            cylinder(base_thickness + standoff_height, standoff_outer_radius, standoff_outer_radius);
        };
        translate([33.78, 19.2, 0]) {
            cylinder(base_thickness + standoff_height, standoff_outer_radius, standoff_outer_radius);
        };
        translate([0, -39, 0]) {
            cylinder(base_thickness + standoff_height, standoff_outer_radius, standoff_outer_radius);
        };
    };
    // The face plate screw holes
    for (i = [0 : 60 : 360]) {
        rotate([0, 0, i]) {
            translate([0, 46.5, 32]) {
                cylinder(10, 1.3, 1.3);
            };
        }
    }
    // The PCB screw holes
    translate([-33.78, 19.2, -1]) {
        cylinder(10, pcb_mounting_hole_radius, pcb_mounting_hole_radius);
    };
    translate([33.78, 19.2, -1]) {
        cylinder(10, pcb_mounting_hole_radius, pcb_mounting_hole_radius);
    };
    translate([0, -39, -1]) {
        cylinder(10, pcb_mounting_hole_radius, pcb_mounting_hole_radius);
    };
    // The cable grommet hole
    translate([0, 0, -1]) {
        cylinder(10, 7.5, 7.5);
    };
    translate([0, 0, 1.5]) {
        cylinder(10, 10, 10);
    };
    // The mounting bolt holes
    translate([-26, 0, -1]) {
        cylinder(10, 3, 3);
    };
    translate([-26, 0, 2]) {
        cylinder(10, 6.5, 6.5);
    };
    translate([26, 0, -1]) {
        cylinder(10, 3, 3);
    };
    translate([26, 0, 2]) {
        cylinder(10, 6.5, 6.5);
    };
    // The button hole
    rotate([0, 0, 130]) {
        translate([46.5, 0, 13]) {
            rotate([0, 90, 0]) {
                union() {
                    translate([0, 0, 5]) {
                        cube([100, 18, 4.6], true);
                    };
                    cylinder(10, 6, 6, true);
                    translate([0, 0, -3]) {
                        cube([18, 18, 4], true);
                    };
                };
            };
        };
    };
};   
  