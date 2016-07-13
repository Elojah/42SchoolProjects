let () =
	let failed_proj = App.App.fail(("GOMOKU", "", 50)) in
	let succeed_proj = App.App.success(("N-Puzzle", "", 50)) in
	let combination = App.App.combine failed_proj succeed_proj in
	App.App.print_proj failed_proj;
	App.App.print_proj succeed_proj;
	App.App.print_proj combination
