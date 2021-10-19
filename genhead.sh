		for f in $@; do
			if ! grep -qE "\w+((\.a)|(\.o))" <<< $f; then
				if ! grep -qE "(By: .* <.*>)" $f; then
					if ! grep -qE "(Created: .*/.*/.* .*:.*:.* by .*)" $f; then
						if ! grep -qE "(Updated: .*/.*/.* .*:.*:.* by .*)" $f; then
							vim -c 'Stdheader' -c 'wq' $f;
						fi
					fi
				fi
			fi
		done
	fi